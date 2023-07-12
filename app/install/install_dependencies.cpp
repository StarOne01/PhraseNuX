#include <cstdlib>
#include <curl/curl.h>
#include <thread>
#include "../../include/AES/aescrypt.c"
#include "../../include/hash/sha3.h"
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
    system("clear");
    cout << "\033[1;36mPlease keep your Internet Turned On\033[0m\n";
    cout << "\033[1;36mHave you turned On ? (Yes/No)\033[0m\n";
    string a;
    cin >> a;
   
            if (a == "Yes" || a == "yes" || a == "y" || a == "Y" || a == "YES")
            {
                string callname;
                cout << "\n\n\033[1;36mPlease enter a command (this will be used to lauch PhraseNuX when you type this keyword anywhere in your terminal)\033[0m\n";
                cin >> callname;
		std::string path = getenv("PATH");
		path += "/";
                std::string exists = path + callname;
                std::ifstream ifile;
                ifile.open(exists);
                while (true)
                {
                    if (ifile)
                    {
                        ifile.close();
                        std::cout << "\n\n\033[1;31mSorry this name is already taken by someother program please enter another name\033[0m\n";
                        std::cin >> callname;
                        exists = "/usr/bin/" + callname;
                        std::ifstream iifile;
                        iifile.open(exists);
                        if (!iifile)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (!ifile)
                    {
                        break;
                    }
                }
                std::ofstream file;
                file.open(callname);
                char tmp[256];
                getcwd(tmp, 256);
                std::string pwd = tmp;
                std::string namee = "cd " + pwd;
                namee.resize(namee.size() - 7);
                file << "#!/" + path + "bash" << std::endl;
                file << namee << std::endl;
                file << "./PhraseNuX" << std::endl;
                file.close();
                std::string nameing = path + callname;
                rename(callname.c_str(), nameing.c_str());
                callname = "chmod u=rx " + path + callname;
                const char *nnamee = callname.c_str();
                system(nnamee);

                cout << "\n\n\033[1;31m\n\nWarning !! : Keep this password very strong and please remember this, IF YOU FORGOT THIS PASSWORD, YOU CAN'T RECOVER ANY OF YOUR PASSWORDS\n\033[0m";
                cout << "\n\n\033[1;32mGuide for Password creation\n\n\n\033[0m";
                cout << "\n\n\033[1;31m•You can use any ASCII values and DONOT include Personal informarion \n•short passwords are PROHIBITED\n•Max Password size = 1024 characters\033[0m\n";
                std::ofstream output("test");
                std::ifstream iiifile;
                iiifile.open("test");
                if (iiifile)
                {
                    int passlen = 0;
                    FILE *infp = NULL;
                    FILE *outfp = NULL;
                    encryptmode_t mode = UNINIT;
                    unsigned char pass_input[MAX_PASSWD_BUF];
                    unsigned char pass[MAX_PASSWD_BUF];
                    char outfile[10];

                    // Initialize the output filename
                    if (mode != UNINIT)
                    {
                        fprintf(stderr, "Error: only specify one of -d or -e\n");
                        cleanup(outfile);
                        return 0;
                    }
                    mode = ENC;

                    if (mode == UNINIT)
                    {
                        fprintf(stderr, "Error: -e or -d not specified\n");
                        cleanup(outfile);
                        return 0;
                    }
                    // Prompt for password if not provided on the command line
                    passlen = read_password(pass_input, mode);

                    switch (passlen)
                    {
                    case 0: //no password in input
                        fprintf(stderr, "Error: No password supplied.\n");
                        cleanup(outfile);
                        return 0;
                    case AESCRYPT_READPWD_FOPEN:
                    case AESCRYPT_READPWD_FILENO:
                    case AESCRYPT_READPWD_TCGETATTR:
                    case AESCRYPT_READPWD_TCSETATTR:
                    case AESCRYPT_READPWD_FGETC:
                    case AESCRYPT_READPWD_TOOLONG:
                        fprintf(stderr, "Error in read_password: %s.\n",
                                read_password_error(passlen));
                        cleanup(outfile);
                        return 0;
                    case AESCRYPT_READPWD_NOMATCH:
                        fprintf(stderr, "Error: Passwords don't match.\n");
                        cleanup(outfile);
                        return 0;
                    }

                    passlen = passwd_to_utf16(pass_input,
                                              strlen((char *)pass_input),
                                              MAX_PASSWD_LEN,
                                              pass);

                    if (passlen < 0)
                    {
                        cleanup(outfile);
                        // For security reasons, erase the password
                        memset(pass, 0, MAX_PASSWD_BUF);
                        return 0;
                    }

                    if (outfp != NULL)
                    {
                        if (outfp != stdout)
                        {

                            fclose(outfp);
                        }
                        fprintf(stderr, "Error: A single output file may not be specified with multiple input files.\n");
                        cleanup(outfile);
                        // For security reasons, erase the password
                        memset(pass, 0, MAX_PASSWD_BUF);
                        return 0;
                    }
                    if (mode == ENC)
                    {
                        rename("Encrypted_Passwords.aes", "test.aes");
                        std::ifstream ifile;
                        ifile.open("test");
                        if (ifile)
                        {
                            const char *infile;
                            infile = "test";
                            infp = fopen(infile, "r");
                            if (outfp == NULL)
                            {
                                snprintf(outfile, 1024, "%s.aes", infile);
                                if ((outfp = fopen(outfile, "w")) == NULL)
                                {
                                    if (infp != NULL)
                                    {
                                        fclose(infp);
                                    }
                                    fprintf(stderr, "Error opening output file %s : ", outfile);
                                    perror("");
                                    cleanup(outfile);
                                    // For security reasons, erase the password
                                    memset(pass, 0, MAX_PASSWD_BUF);
                                }
                            }
                        }
                        encrypt_stream(infp, outfp, pass, passlen);
                        remove("test");
                        rename("test.aes", "Encrypted_Passwords.aes");
                    }
                    if (infp != NULL)
                    {
                        fclose(infp);
                    }
                    if (outfp != NULL)
                    {
                        fclose(outfp);
                    }

                    // Reset input/output file names and desriptors
                    outfile[0] = '\0';
                    infp = NULL;
                    outfp = NULL;

                    // For security reasons, erase the password
                    memset(pass, 0, MAX_PASSWD_BUF);
                    system("chmod +x start");
                    system("bash start");
                }
            }
            else
            {
                if (a == "No" || a == "NO" || a == "N" || a == "n" || a == "no")
                {
                    system("exit");
                    cout << "\033[1;31mPlease try again later when network is available\n\033[0m";
                    return 1;
                }
	    }
}
