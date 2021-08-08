#include <thread>
#include <chrono>
#include "../AES/aescrypt.c"
#include "../hash/sha3.h"
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

bool checkformodification(std::string a, std::string b)
{
    std::string filen = a;
    std::string algorithm = "3";
    SHA3 digestSha3(SHA3 ::Bits256);
    const size_t BufferSize = 144 * 7 * 1024;
    char *buffer = new char[BufferSize];
    std::ifstream file;
    std::istream *input = NULL;

    file.open(filen.c_str(), std::ios::binary);
    if (!file)
    {
        std::cerr << "Error ! Cannot open " << filen << std::endl;
    }
    input = &file;

    while (*input)
    {
        input->read(buffer, BufferSize);
        size_t numBytesRead = size_t(input->gcount());
        digestSha3.add(buffer, numBytesRead);
    }

    file.close();
    delete[] buffer;

    if (digestSha3.getHash() == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    system("clear");
    cout << "\033[1;36mPlease keep your Internet Turned On\033[0m\n";
    cout << "\033[1;36mHave you turned On ? (Yes/No)\033[0m\n";
    string a;
    cin >> a;
    std::string shathree;
    std::ifstream shasum("PhraseNuX.shasum");
    while (getline(shasum, shathree))
    {
	if(checkformodification("PhraseNuX.cpp","60d3a1b6b3beb0ea639f6120dedd0f9764b8357bd191f84866d9813de50e0f28") && checkformodification("start","ddbdeb47bfdac8a1b8c4f3c22aac07feee0b38e6391f221254c9075e4bf7ec12") && checkformodification("install_dependencies.cpp", shathree) && checkformodification("update","b3dbdb7a2ac2bc1de53c2569c4964ac3682e58542a474e2e645eb2590eba89c8") && checkformodification("../hash/sha3.cpp","8c070dbc66dee46ce8340a6c83264c922199e51ebabbc675ea0bb08301bab7fa") && checkformodification("../hash/sha3.h","302478a22134b2eb1a598cd48d331fe80c4233d3dbe90a8508ff200477e73503") && checkformodification("../AES/aes.c","b36fa2cb10a6f1c6e49359ca5c0d6e1f6fcb3cc1fc7cddafc6a4e94544c2bad1") && checkformodification("../AES/aes.h","90188c6c8375e92166289c0cddcebc0ee539c625cd2195ee52ec47be5d6a6cf9") && checkformodification("../AES/aescrypt.c","246a44d2dafff022f017ecda75b5485ef1c9158772d8a685036d6a800c1c1b10") && checkformodification("../AES/aescrypt.h","ba89f719de52f87a7eef262432d46983bfe8461fae4d2f4dfb899304fb6676c3") && checkformodification("../AES/password.c","7021ffdf118384ac85925a5e8e72e6b860dfd3f5ffed8bff01ed0a6d854a0fdc") && checkformodification("../AES/password.h","d31a8c73b435c68227b39a5ca4294b59d04de1d7a91db0df995250cebe214727") && checkformodification("../AES/sha256.h","19d1265c31b7229e05744cd8b522977a987350cc458955fef0fd388a2484dbe2") && checkformodification("../AES/sha256.c","4b45ba97266a280db3aade5de4cc25420979bfedd4891c73153970fec94a8d3f") && checkformodification("../AES/version.h","9f53d8690c6226af4376bd4f57e3c3180df2da5c4795db3dfd19e719a9647f1d") && checkformodification("../random/csprng.cpp","8b409deb0f2e086d00c99d2765dd56713bb33d16c675d12fe5c6903c35d50989") && checkformodification("../random/csprng.h","c3e5389b011088b5e5ab6c68c08cc3b952215bd52c7a28968b74c993d626afe2") && checkformodification("../random/csprng.hpp","1cb15d8415a63fce15cc85ddcd15666973e2fb41c4edfbd3b11503ced6ba589e") && checkformodification("../random/is_iterable.hpp","4ab295afd50988c2562d89362ae7deaf91653c5d997258525396e61bf7cc96e5"))
        {
            shasum.close();
            if (a == "Yes" || a == "yes" || a == "y" || a == "Y" || a == "YES")
            {
                string callname;
                cout << "\n\n\033[1;36mPlease enter a command (this will be used to lauch PhraseNuX when you type this keyword anywhere in your terminal)\033[0m\n";
                cin >> callname;
                std::string exists = "/usr/bin/" + callname;
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
                file << "#!/bin/bash" << std::endl;
                file << namee << std::endl;
                file << "./PhraseNuX" << std::endl;
                file.close();
                std::string nameing = "/usr/bin/" + callname;
                rename(callname.c_str(), nameing.c_str());
                callname = "chmod u=rx /usr/bin/" + callname;
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
        else
        {
            shasum.close();
            std::cout << "\n\n\033[1;31mOOPs! Looks like some or all files have been corrupted ! \033[0m\n";
            if (checkformodification("update", "b3dbdb7a2ac2bc1de53c2569c4964ac3682e58542a474e2e645eb2590eba89c8"))
            {
                std::cout << "\n\n\033[1;31mOkay, No problems we will securely solve this problem soo, please donot close this terminal or turn off network access\033[0m\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                system("chmod +x update && bash update");
                return 1;
            }
            else
            {
                std::cout << "\n\n\033[1;31mSo, please clone this repository once again, then everything will be solved\033[0m\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                return 0;
            }
        }
    }
}
