#include <thread>
#include <chrono>
#include "../AES/aescrypt.c"
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;
int main(){
system("clear");
cout << "Please keep your Internet Turned On " << endl;
cout << "Have you turned On ? (Yes/No) " << endl;
string a;
cin >> a;
//if(checkformodification("start", "10a72e2e389ab6d338e417d87dcaa67f9bb804ff40e9ba7ccf120a2dc0bb6820") && checkformodification("install_dependencies.cpp", "185e1ec2fcb6d36b9a44571b3fa0fb354c430fbf631a015b46d411ca7c3dedb4") && checkformodification("../random/csprng.cpp", "8b409deb0f2e086d00c99d2765dd56713bb33d16c675d12fe5c6903c35d50989") && checkformodification("../random/csprng.h", "c3e5389b011088b5e5ab6c68c08cc3b952215bd52c7a28968b74c993d626afe2") && checkformodification("../random/csprng.hpp", "1cb15d8415a63fce15cc85ddcd15666973e2fb41c4edfbd3b11503ced6ba589e") && checkformodification("../random/is_iterable.hpp", "4ab295afd50988c2562d89362ae7deaf91653c5d997258525396e61bf7cc96e5") && checkformodification("../hash/sha3.cpp", "8c070dbc66dee46ce8340a6c83264c922199e51ebabbc675ea0bb08301bab7fa") &&  checkformodification("../hash/sha3.h", "302478a22134b2eb1a598cd48d331fe80c4233d3dbe90a8508ff200477e73503")){ 
if (a == "Yes" || a == "yes" || a == "y" || a == "Y" || a == "YES"){
string callname;
cout << "\n\nPlease enter the command to start the Program i.e, the word which you enter now will be used to call the program\n";
cin >>callname;
std::string exists = "/usr/bin/" + callname;
std::ifstream ifile;
ifile.open(exists);
while (true){
if(ifile){
ifile.close();
std::cout << "\n\nSorry this name is already taken by someother program please enter another name\n";
std::cin >> callname;
exists = "/usr/bin/" + callname;
std::ifstream iifile;
iifile.open(exists);
if(!iifile){
break;
}
else {
continue;
}}
if (!ifile) {
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
file << "#!/bin/bash" << std::endl;
file << namee << std::endl;
file << "./PhraseNUX" << std::endl;
file.close();
std::string nameing = "/usr/bin/" + callname;
rename(callname.c_str(), nameing.c_str());
callname = "chmod u=rx /usr/bin/" + callname;
const char* nnamee = callname.c_str();
system(nnamee);
std::ofstream output("test");
std::ifstream iiifile;
iiifile.open("test");
if(iiifile){
    int passlen=0;
    FILE *infp = NULL;
    FILE *outfp = NULL;
    encryptmode_t mode=UNINIT;
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

        passlen = passwd_to_utf16(  pass_input,
                                    strlen((char*)pass_input),
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
        if (outfp != stdout){

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
          if (ifile){
          const char *infile;
          infile = "test";
          infp = fopen(infile, "r");
        if (infp == NULL){
          std::cout << "\n\n\nError !! Encrypted password file is is Missing ! \n\nDid you moved a file called \"test.aes\" anywhere ?\n\n";
          std::this_thread::sleep_for(std::chrono::milliseconds(4000));
          return 0;
        }
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
else {
    if (a == "No" || a == "NO" || a == "N" || a == "n" || a == "no"){
    system("exit");
    cout << "Please try again later when network is available\n";
    }
//}
}
}
