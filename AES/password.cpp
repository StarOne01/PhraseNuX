/*
 * AES Crypt for Linux
 * Copyright (C) 2007-2016
 *
 * Contributors:
 *     Glenn Washburn <crass@berlios.de>
 *     Paul E. Jones <paulej@packetizer.com>
 *     Mauro Gilardi <galvao.m@gmail.com>
 *
 * This software is licensed as "freeware."  Permission to distribute
 * this software in source and binary forms is hereby granted without a
 * fee.  THIS SOFTWARE IS PROVIDED 'AS IS' AND WITHOUT ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * THE AUTHOR SHALL NOT BE HELD LIABLE FOR ANY DAMAGES RESULTING FROM
 * THE USE OF THIS SOFTWARE, EITHER DIRECTLY OR INDIRECTLY, INCLUDING,
 * BUT NOT LIMITED TO, LOSS OF DATA OR DATA BEING RENDERED INACCURATE.
 *
 */

#define _POSIX_C_SOURCE 200112L

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>   // getopt
#include <stdlib.h>   // malloc
#include <locale.h>   // setlocale
#include <iconv.h>    // iconv
#include <langinfo.h> // nl_langinfo
#include <errno.h>    // errno
#include <termios.h>  // tcgetattr,tcsetattr

#include "password.h"

/*
 *  read_password_error
 *
 *  Returns the description of the error when reading the password.
 */
const char *read_password_error(int error)
{
    if (error == AESCRYPT_READPWD_FOPEN)
        return "fopen()";
    if (error == AESCRYPT_READPWD_FILENO)
        return "fileno()";
    if (error == AESCRYPT_READPWD_TCGETATTR)
        return "tcgetattr()";
    if (error == AESCRYPT_READPWD_TCSETATTR)
        return "tcsetattr()";
    if (error == AESCRYPT_READPWD_FGETC)
        return "fgetc()";
    if (error == AESCRYPT_READPWD_TOOLONG)
        return "password too long";
    if (error == AESCRYPT_READPWD_NOMATCH)
        return "passwords don't match";
    return "No valid error code specified!!!";
}

/*
 *  read_password
 *
 *  This function reads at most 'MAX_PASSWD_LEN'-1 characters
 *  from the TTY with echo disabled, putting them in 'buffer'.
 *  'buffer' MUST BE ALREADY ALLOCATED!!!
 *  When mode is ENC the function requests password confirmation.
 *
 *  Return value:
 *    >= 0 the password length (0 if empty password is in input)
 *    < 0 error (return value indicating the specific error)
 */

int read_password(unsigned char *buffer, encryptmode_t mode)
{
    struct termios t; // Used to set ECHO attribute
    int echo_enabled; // Was echo enabled?
    int tty;          // File descriptor for tty
    FILE *ftty;       // File for tty
    unsigned char pwd_confirm[MAX_PASSWD_BUF];
    // Used for password confirmation
    int c;            // Character read from input
    int chars_read;   // Chars read from input
    unsigned char *p; // Password buffer pointer
    int i;            // Loop counter
    int match;        // Do the two passwords match?

    // Open the tty
    ftty = fopen("/dev/tty", "r+");
    if (ftty == NULL)
    {
        return AESCRYPT_READPWD_FOPEN;
    }
    tty = fileno(ftty);
    if (tty < 0)
    {
        return AESCRYPT_READPWD_FILENO;
    }

    // Get the tty attrs
    if (tcgetattr(tty, &t) < 0)
    {
        fclose(ftty);
        return AESCRYPT_READPWD_TCGETATTR;
    }

    // Round 1 - Read the password into buffer
    // (If encoding) Round 2 - read password 2 for confirmation
    for (i = 0; (i == 0) || (i == 1 && mode == ENC); i++)
    {
        // Choose the buffer where to put the password
        if (!i)
        {
            p = buffer;
        }
        else
        {
            p = pwd_confirm;
        }

        // Prompt for password
        if (i)
        {
            std::cout << "\033[5;36m\n(invisible)\033[0m";
            fprintf(ftty, "\033[5;36m\nRe-Enter Your Password:\033[0m");
        }
        else
        {
            std::cout << "\033[5;36m\n(invisible)\033[0m";
            fprintf(ftty, "\033[5;36m\nEnter Your Password:\033[0m");
        }
        fflush(ftty);

        // Disable echo if necessary
        if (t.c_lflag & ECHO)
        {
            t.c_lflag &= ~ECHO;
            if (tcsetattr(tty, TCSANOW, &t) < 0)
            {
                // For security reasons, erase the password
                memset(buffer, 0, MAX_PASSWD_BUF);
                memset(pwd_confirm, 0, MAX_PASSWD_BUF);
                fclose(ftty);
                return AESCRYPT_READPWD_TCSETATTR;
            }
            echo_enabled = 1;
        }
        else
        {
            echo_enabled = 0;
        }

        // Read from input and fill buffer till MAX_PASSWD_LEN chars are read
        chars_read = 0;
        while (((c = fgetc(ftty)) != '\n') && (c != EOF))
        {
            // fill buffer till MAX_PASSWD_LEN
            if (chars_read <= MAX_PASSWD_LEN + 1)
            {
                if (chars_read <= MAX_PASSWD_LEN)
                    p[chars_read] = (char)c;
                chars_read++;
            }
        }

        if (chars_read <= MAX_PASSWD_LEN)
        {
            p[chars_read] = '\0';
        }

        fprintf(ftty, "\n");

        // Enable echo if disabled above
        if (echo_enabled)
        {
            t.c_lflag |= ECHO;
            if (tcsetattr(tty, TCSANOW, &t) < 0)
            {
                // For security reasons, erase the password
                memset(buffer, 0, MAX_PASSWD_BUF);
                memset(pwd_confirm, 0, MAX_PASSWD_BUF);
                fclose(ftty);
                return AESCRYPT_READPWD_TCSETATTR;
            }
        }

        // check for EOF error
        if (c == EOF)
        {
            // For security reasons, erase the password
            memset(buffer, 0, MAX_PASSWD_BUF);
            memset(pwd_confirm, 0, MAX_PASSWD_BUF);
            fclose(ftty);
            return AESCRYPT_READPWD_FGETC;
        }

        // Check chars_read.  The password must be maximum MAX_PASSWD_LEN
        // chars.  If too long an error is returned
        if (chars_read > MAX_PASSWD_LEN)
        {
            // For security reasons, erase the password
            memset(buffer, 0, MAX_PASSWD_BUF);
            memset(pwd_confirm, 0, MAX_PASSWD_BUF);
            fclose(ftty);
            return AESCRYPT_READPWD_TOOLONG;
        }
    }

    // Close the tty
    fclose(ftty);

    // Password must be compared only when encrypting
    if (mode == ENC)
    {
        // Check if passwords match
        match = strcmp((char *)buffer, (char *)pwd_confirm);
        memset(pwd_confirm, 0, MAX_PASSWD_BUF);

        if (match != 0)
        {
            // For security reasons, erase the password
            memset(buffer, 0, MAX_PASSWD_BUF);
            return AESCRYPT_READPWD_NOMATCH;
        }
    }

    return chars_read;
}

/*
 *  passwd_to_utf16
 *
 *  Convert String to UTF-16LE for windows compatibility
 */
int passwd_to_utf16(unsigned char *in_passwd,
                    int length,
                    int max_length,
                    unsigned char *out_passwd)
{
    unsigned char *ic_outbuf,
        *ic_inbuf;
    iconv_t condesc;
    size_t ic_inbytesleft,
        ic_outbytesleft;

    /* Max length is specified in character, but this function deals
     * with bytes.  So, multiply by two since we are going to create a
     * UTF-16 string.
     */
    max_length *= 2;

    ic_inbuf = in_passwd;
    ic_inbytesleft = length;
    ic_outbytesleft = max_length;
    ic_outbuf = out_passwd;

    /* Set the locale based on the current environment */
    setlocale(LC_CTYPE, "");

    if ((condesc = iconv_open("UTF-16LE", nl_langinfo(CODESET))) ==
        (iconv_t)(-1))
    {
        perror("Error in iconv_open");
        return -1;
    }

    if (iconv(condesc,
              (char **const)&ic_inbuf,
              &ic_inbytesleft,
              (char **const)&ic_outbuf,
              &ic_outbytesleft) == (size_t)-1)
    {
        switch (errno)
        {
        case E2BIG:
            fprintf(stderr, "\033[1;31mError: password too long\e[0m\n");
            iconv_close(condesc);
            return -1;
            break;
        default:
            /*
                printf("\nEILSEQ(%d), EINVAL(%d), %d\n",
                       EILSEQ,
                       EINVAL,
                       errno);
                */
            perror("\033[1;31mPassword conversion error\e[0m");
            iconv_close(condesc);
            return -1;
        }
    }
    iconv_close(condesc);
    return (max_length - ic_outbytesleft);
}
