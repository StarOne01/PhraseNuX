#include <curl/curl.h>
#include <thread>
#include <chrono>
#include "../AES/aescrypt.c"
#include "../hash/sha3.h"
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
        ((std::string *)userp)->append((char *)contents, size * nmemb);
        return size * nmemb;
}

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
	if(checkformodification("PhraseNuX.cpp","50744cc4fd68523b0bf80a496d1e77141c0a28ec53d3339945c186fab3501c8e") && checkformodification("start","3126d01f2057a1218b4300e56af7579f63924581a97b096e1016d034f09f7e52") && checkformodification("install_dependencies.cpp", shathree) && checkformodification("update","0552d3158a2bcfda0f577c5f0fe2fb624ba17d5660dd8bafd9c5dd3e871889c1") && checkformodification("../hash/sha3.cpp","8c070dbc66dee46ce8340a6c83264c922199e51ebabbc675ea0bb08301bab7fa") && checkformodification("../hash/sha3.h","302478a22134b2eb1a598cd48d331fe80c4233d3dbe90a8508ff200477e73503") && checkformodification("../AES/aes.cpp","36316e945644cc8e15727569460b55c80c15154c176089d798898e0c6d80fb8d") && checkformodification("../AES/aes.h","e4145a4034b7b8147efcd6399c8d096ff11e2c2adb19dfbc94078237d06f761c") && checkformodification("../AES/aescrypt.c","263cc14ae65a3f99d068b745dd3ff97cdccc3d0c5c8f23e97a48173ef07f2177") && checkformodification("../AES/aescrypt.h","6a06dccf8ecbe0cf07bf9f36be6eccfe72bc151e7ed0300b062c89783b15a73f") && checkformodification("../AES/password.cpp","442d19b43e98ee369381476b66c0cb75be9d3ce5040ac07d4496742d8b8d80c5") && checkformodification("../AES/password.h","d31a8c73b435c68227b39a5ca4294b59d04de1d7a91db0df995250cebe214727") && checkformodification("../AES/sha256.h","51e7f1fef240e421ead1e6f790d6e5e34287174e17b54c6262d85938271e0057") && checkformodification("../AES/sha256.c","35cbbaa00a47c469f7e5190c739614ec0e48ed1fed867ce2870cabd67357b934") && checkformodification("../AES/version.h","9f53d8690c6226af4376bd4f57e3c3180df2da5c4795db3dfd19e719a9647f1d") && checkformodification("../random/csprng.cpp","8b409deb0f2e086d00c99d2765dd56713bb33d16c675d12fe5c6903c35d50989") && checkformodification("../random/csprng.h","c3e5389b011088b5e5ab6c68c08cc3b952215bd52c7a28968b74c993d626afe2") && checkformodification("../random/csprng.hpp","1cb15d8415a63fce15cc85ddcd15666973e2fb41c4edfbd3b11503ced6ba589e") && checkformodification("../random/is_iterable.hpp","4ab295afd50988c2562d89362ae7deaf91653c5d997258525396e61bf7cc96e5"))
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
            if (checkformodification("update", "0552d3158a2bcfda0f577c5f0fe2fb624ba17d5660dd8bafd9c5dd3e871889c1"))
            {
                std::cout << "\n\n\033[1;31mOkay, No problems we will securely solve this problem soo, please donot close this terminal or turn off network access\033[0m\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                system("chmod +x update && bash update");
                return 1;
            }
            else
            {
		for (int downcount = 0; downcount <= 10; downcount++)
                                        {
                                                std::cout << "\033[1;31mError!! could not start the update script because it is been modified and became untrusted\n\nPlease turn your network connection on\033[0m\n\n";
                                                std::this_thread::sleep_for(std::chrono::milliseconds(6000));
                                                CURL *curl3;
                                                CURLcode res3;
                                                std::string readBuffer3;

                                                curl3 = curl_easy_init();
                                                if (curl3)
                                                {
                                                        curl_easy_setopt(curl3, CURLOPT_URL, "https://tamilanth.github.io/PhraseNuX/main/updatescript/");
                                                        curl_easy_setopt(curl3, CURLOPT_WRITEFUNCTION, WriteCallback);
                                                        curl_easy_setopt(curl3, CURLOPT_WRITEDATA, &readBuffer3);
                                                        res3 = curl_easy_perform(curl3);
                                                        if (res3 == 6)
                                                        {
                                                                std::cout << "\033[1;31mPlease turn on your network and then again run this program\033[0m\n\n";
                                                                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                                        }
                                                        curl_easy_cleanup(curl3);
                                                        std::ofstream updatedown("update");
                                                        updatedown << readBuffer3;
                                                        updatedown.close();
                                                        if (checkformodification("update", "0552d3158a2bcfda0f577c5f0fe2fb624ba17d5660dd8bafd9c5dd3e871889c1"))
                                                        {
                                                                break;
                                                        }
                                                        if (!checkformodification("update", "0552d3158a2bcfda0f577c5f0fe2fb624ba17d5660dd8bafd9c5dd3e871889c1") && downcount == 10)
                                                        {
                                                                std::cout << "\033[1;31m\n\n\n\n\n\n\nLooks like our developer forgot to update the sha values please say him this by starting a github discussion\033[0m\n\n";
                                                                std::this_thread::sleep_for(std::chrono::milliseconds(8000));
                                                                break;
                                                        }
                                                }
                                        }
                                        system("chmod u=rx update");
                                        system("bash update");
                                        return true;
            }
        }
    }
}
