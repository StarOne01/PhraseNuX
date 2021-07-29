/*
PhraseNUX was created && developed && is being maintained by Prashanth(Tamilanth)
© Tamilanth
PhraseNUX is free to use and free to be modified and distributed as per the GPL License
for more information on modification and distribution, please refer to LICENSE.md
Incase of any bugs please tag me by posting "Found a Bug @MY_USWLERNAME" at 
		• Instagram (@its_me_tamilanth) or
		• Twitter (@Tamilanth)
for further Instructions

Thanking you
Prashanth
*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <chrono>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <thread>
#include "../random/csprng.hpp"
#include "../hash/sha3.h"
#include "../AES/aescrypt.c"
#include <filesystem>


//Random integer creator

unsigned long long int randomize()
{
	duthomhas::csprng rng;
        unsigned long long int b = 9999 * 99999 * (rng() % 999999999999999999);
        return b;
}


//integer to string converter

std::string str(unsigned long long int i)
{
	duthomhas::csprng rng;
        std::string x = std::to_string(i);
        return x;
}
//Declaring all functions and checkers
bool aescrypt(char type,const char** pas);
void checkforupdates(bool start);
void clearallpass();
void addpassmanually();
void changepass();
void safeenterstop();
void selectservice();
void advancedoptions();
std::string safeenter();
void showpass(bool what);
void waitup(int a);
void veripassfore(std::string passstr);
bool veripassford(std::string passstr);
void startup();
signed int rc = -1;
signed int enrc = -1;
void secdel();
void banner();
void alphaonlyfn();
void call(int mini, int max, short int ik);
void smallbanner();
std::string pwdfile(std::string filename1);


//function to delete passwords

void delpass()
{
        std::string line;
	std::cout << std::endl;
        std::cout << "\033[1;31mEnter Your Password:\033[0m\n\n";
        std::string lll = safeenter();
        if (veripassford(lll)){
	showpass(0);
        secdel();
	std::cout << std::endl << std::endl;
	veripassford(lll);
	secdel();
        std::string deletethis;
	std::cout << "\033[1;31mEnter the password (with tags) to be deleted\e[0m\n";
        std::getline(std::cin >> std::ws, deletethis);
        veripassford(lll);
        std::ifstream oldfile("test");
        if (!oldfile.is_open())
        {
                std::cout << "\noperation failed !!!\n";
        }
        std::ofstream newfile("testw");
        while(getline(oldfile, line))
        {
                if (line != deletethis)
                newfile << line << std::endl;
        }
        oldfile.close();
        newfile.close();
        secdel();
        rename("testw", "test");
        veripassfore(lll);
        lll = "0eidhsjgsksgsizsywiabhaishsiwywoanshs";
        startup();
	}

}

//Function to write to the password file

void writetofile(std::string ea, short int opt)
{
        std::string lll;
        std::cout << std::endl;
        std::cout << ea << std::endl << std::endl;
        std::cout << "\033[1;34mCan we save this password ?, if not you can generate the password again without saving this\033[0m\n\n";
        std::cout << "\033[1;36m[1] - Save the password \033[0m\n";
        std::cout << "\033[1;36m[2] - Generate a password again \033[0m\n\n";
        short int optionsforsaving;
        std::cin >> optionsforsaving;
        std::cout << "\n";
        if(optionsforsaving == 1){
        std::cout << "\033[1;31mEnter Your Password:\033[0m\n\n";
        lll = safeenter();
        std::string tag;
        std::cout << "\033[5;36m\nPlease enter the name for this password, so you can identify the passwords with names when you decrypt the passwords:\033[0m\n\n\n";
	std::getline(std::cin >> std::ws, tag);
        std::cout << "\n";
        if(veripassford(lll)){
        std::ofstream file;
        file.open("test", std::ios_base::app);
        std::string writinginput = ea + "-------" + tag + "\n";
        file << writinginput;
        file.close();
        veripassfore(lll);
        lll = "00000000teidhsjgsksgsizsywiabhaishsiwywoanshs";
        secdel();
        }
	}
        else {
                if (optionsforsaving == 2){
                        opt == 1 ? call(48, 57, 1) : opt == 2 ? alphaonlyfn() :  call(33, 126, 3);
                		          }
		else {
			std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
       			std::cout << "\033c";
                }			}
}

//Function that displays the custom option banner

void optionsB()
{       std::cout << std::endl;
        std::cout << "\033[5;36m[1] - Numbers Only Mode \033[0m\n";
        std::cout << "\033[5;36m[2] - Alphabets Only Mode \033[0m\n";
        std::cout << "\033[5;36m[3] - Mixed Mode \033[0m\n";
        std::cout << "\033[5;36m[4] - Main Menu \033[0m\n\n";
}



static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


//Function that checks for any modification to the codes of the project


bool checkformodification(std::string a, std::string b)
{
  std::string filen  = a;
  std::string algorithm = "3";
  SHA3 digestSha3  (SHA3  ::Bits256);
  const size_t BufferSize = 144*7*1024;
  char* buffer = new char[BufferSize];
  std::ifstream file;
  std::istream* input = NULL;

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
      digestSha3  .add(buffer, numBytesRead);
  }

  file.close();
  delete[] buffer;

    if (digestSha3.getHash() == b){
    return true;
    }
    else {
    return false;
    }
}

//Funtion that displays the main menu

void optionsA()
{
        std::cout << "\033c";
        banner();
        std::cout << "                Welcome to PhraseNUX\n";
        std::cout << "         ( A password manager by Tamilanth )  " << std::endl
                 << std::endl;
        smallbanner();
        std::cout << "\033[5;36m[1] - Show Saved Passwords\033[0m\n";
        std::cout << "\033[5;36m[2] - Create a  New Password\033[0m\n";
        std::cout << "\033[5;36m[3] - Delete a Password\033[0m\n";
        std::cout << "\033[5;36m[4] - Exit\033[0m\n";
	std::cout << "\033[5;36m[5] - Advanced\033[0m\n\n\n";
}

//Function that makes the program wait for specific timw

void waitup(int a)
{
        std::cout << "\033[1;31m\n\nNote: For security reasons your terminal will be cleared in " << a << " seconds\n\033[0m\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(a * 1000));
        std::cout << "\033c";
}

//Function which acts like "main" function

void startup()
{
        optionsA();
        std::string Jj;
        std::cout << "Please select your Option 1 or 2 or 3 or 4:\n";
        std::cin >> Jj;
        if (Jj == "3")
        {
                delpass();
        }
        else {

        if (Jj == "4")
        {
                exit(1);
        }
        else {

        if (Jj == "2")
        {
                optionsB();
                std::string Option;
                std::cin >> Option;
                Option == "1" ? call(48, 57, 1) : Option == "2" ? alphaonlyfn() :  Option == "3" ? call(33, 126, 3) : Option == "4" ?  startup() :  startup();
        }
        else {

        if (Jj == "Decrypt" || Jj == "decrypt" || Jj == "D" || Jj == "d" || Jj == "1" || Jj == "DECRYPT")
        {
		std::cout << std::endl  << std::endl;
		const char* pass = "0";
		aescrypt('d', &pass);
		showpass(1);
                secdel();
                startup();
        }
        else {
	if (Jj == "5") {
		advancedoptions();
			}
		else {
                std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                startup();
			}
                }
                }
                }
        }
}

//Main
int main()
{
//if(checkformodification("start", "10a72e2e389ab6d338e417d87dcaa67f9bb804ff40e9ba7ccf120a2dc0bb6820") && checkformodification("install_dependencies.cpp", "185e1ec2fcb6d36b9a44571b3fa0fb354c430fbf631a015b46d411ca7c3dedb4") && checkformodification("../random/csprng.cpp", "8b409deb0f2e086d00c99d2765dd56713bb33d16c675d12fe5c6903c35d50989") && checkformodification("../random/csprng.h", "c3e5389b011088b5e5ab6c68c08cc3b952215bd52c7a28968b74c993d626afe2") && checkformodification("../random/csprng.hpp", "1cb15d8415a63fce15cc85ddcd15666973e2fb41c4edfbd3b11503ced6ba589e") && checkformodification("../random/is_iterable.hpp", "4ab295afd50988c2562d89362ae7deaf91653c5d997258525396e61bf7cc96e5") && checkformodification("../hash/sha3.cpp", "8c070dbc66dee46ce8340a6c83264c922199e51ebabbc675ea0bb08301bab7fa") &&  checkformodification("../hash/sha3.h", "302478a22134b2eb1a598cd48d331fe80c4233d3dbe90a8508ff200477e73503"))
//{
	std::cout << "\033c";
	checkforupdates(1);
        return 0;
//}
//else {
//exit(1);
//cout << "Some or all files are corrupted
//}
}

//Password verification for decryption

bool veripassford(std::string passstr)
{
	std::cout << std::endl;
        const char *Opennn = passstr.c_str();
        aescrypt('d', &Opennn);
        passstr = "iyinaishsiwywoanshs";
	std::ifstream fortest2;
        fortest2.open("test");
        if(fortest2) {
	fortest2.close();
	}
	else {
	std::cout << "\033[1;31m\n\nError:!: Incorrect Password or the password file is altered\033[0m\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        startup();
			return 0;
	}
	return 1;
}

//Password verification for encryption

void veripassfore(std::string parssstr)
{
	std::ifstream ifile;
  	ifile.open("test");
   	if(ifile && rc == 1 || rc == 0){
	ifile.close();
	std::cout << std::endl;
        const char *Starboy = parssstr.c_str();
        aescrypt('e', &Starboy);
        parssstr = "8jgftjjnshs";
        secdel();
	}
	else {
	std::cout << "\033[1;31mError:!: Incorrect Password or the password file is altered\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        secdel();
                        startup();
                }
}

//Writing to file for secure delete

void writetofileforsd(std::string dea)
{
        for (short int hhh = 0; hhh <= 35; hhh++)
        {
                std::ofstream file;
                file.open("test");
                file << dea;
                file.close();
        }
}

//Function for secure deletion

void secdel()
{
        long long unsigned int acaa = randomize();
        long long unsigned int bcbb = randomize();
        std::string aaaab = str(acaa);
        std::string baaab = str(bcbb) + aaaab;
        std::string erapt = aaaab + baaab + aaaab + baaab + aaaab + baaab + aaaab + baaab;
        writetofileforsd(erapt);
        system("srm -z test");
	remove("test");
}


//Banners

void smallbanner()
{
	std::cout << "\033[5;36m                 ▁▂▄▅▆▇█ ƬΛ █▇▆▅▄▂▁         \033[0m\n\n";
}

void banner1()
{
        std::cout << "\033[1;36m\n\n";
        std::cout << "\033[1;36m                  ________________\n";
        std::cout << "\033[1;36m                 |__   __|(  ___  )\n";
        std::cout << "\033[1;36m                    ) (   | (   ) |\n";
        std::cout << "\033[1;36m                    | |   | (___) |\n";
        std::cout << "\033[1;36m                    | |   |  ___  |\n";
        std::cout << "\033[1;36m                    | |   | (   ) |\n";
        std::cout << "\033[1;36m                    | |   | )   ( |\n";
        std::cout << "\033[1;36m                    )_(   |_|   |_|\033[0m\n\n\n\n";
}

void banner2()
{
        std::cout << "\033[5;36m\n\n";
        std::cout << "\033[5;36m                  |''||''|     |\n";
        std::cout << "\033[5;36m                     ||       |||\n";
        std::cout << "\033[5;36m                     ||      |  ||\n";
        std::cout << "\033[5;36m                     ||     .''''|.\n";
        std::cout << "\033[5;36m                    .||.   .|.  .||.\033[0m\n\n\n\n";
}

void banner3()
{
        std::cout << "\033[5;36m\n\n";
        std::cout << "\033[5;36m                     ╭━━━━┳━━━╮    \n";
        std::cout << "\033[5;36m                     ┃╭╮╭╮┃╭━╮┃    \n";
        std::cout << "\033[5;36m                     ╰╯┃┃╰┫┃╱┃┃    \n";
        std::cout << "\033[5;36m                     ╱╱┃┃╱┃╰━╯┃    \n";
        std::cout << "\033[5;36m                     ╱╱┃┃╱┃╭━╮┃    \n";
        std::cout << "\033[5;36m                     ╱╱╰╯╱╰╯╱╰╯    \033[0m\n\n\n\n";
}

void banner4()
{
	std::cout << "\033[1;36m\n\n";
	std::cout << "\033[1;36m		  ▄▄▄█████▓ ▄▄▄      \n";
	std::cout << "\033[1;36m		  ▓  ██▒ ▓▒▒████▄    \n";
	std::cout << "\033[1;36m		  ▒ ▓██░ ▒░▒██  ▀█▄  \n";
	std::cout << "\033[1;36m		  ░ ▓██▓ ░ ░██▄▄▄▄██ \n";
	std::cout << "\033[1;36m		    ▒██▒ ░  ▓█   ▓██▒\n";
	std::cout << "\033[1;36m		    ▒ ░░    ▒▒   ▓▒█░\n";
	std::cout << "\033[1;36m		      ░      ▒   ▒▒ ░\n";
	std::cout << "\033[1;36m	       	    ░        ░   ▒   \n";
	std::cout << "\033[1;36m	                  ░  ░\033[0m\n\n\n\n";
}
void banner5()
{
	std::cout << "\033[1;36m\n\n";
 	std::cout << "\033[1;36m		  '||''|.  '||' '|'\n"; 
 	std::cout << "\033[1;36m	           ||   ||   || |   \n";
 	std::cout << "\033[1;36m         	   ||...|'    ||    \n";
	std::cout << "\033[1;36m		   ||        | ||   \n";
	std::cout << "\033[1;36m		  .||.     .|   ||. \033[0m\n\n\n\n";

}

void banner6()
{
	std::cout << "\033[1;36m\n\n";
	std::cout << "\033[1;36m	 ,ggggggggggg,   ,ggg,          ,gg\n";
	std::cout << "\033[1;36m	dP\"\"\"88\"\"\"\"\"\"Y8,dP\"\"\"Y8,      ,dP' \n";
	std::cout << "\033[1;36m	Yb,  88      `8bYb,_  \"8b,   d8\"   \n";
	std::cout << "\033[1;36m	 `\"  88      ,8P `\"\"    Y8,,8P'    \n";
	std::cout << "\033[1;36m	     88aaaad8\"          Y88\"      \n";
	std::cout << "\033[1;36m	     88\"\"\"\"\"            ,888b      \n";
	std::cout << "\033[1;36m	     88                d8\" \"8b,   \n";
	std::cout << "\033[1;36m	     88              ,8P'    Y8,   \n";
	std::cout << "\033[1;36m	     88             d8\"       \"Yb, \n";
	std::cout << "\033[1;36m	     88           ,8P\'          \"Y8 \033[0m\n\n\n\n";
}
void banner7()
{                                   
                                   
                                   
                                   
                                   
                                   

}

/*
                  
    	std::cout << "\033[5;36m	                 
    	std::cout << "\033[5;36m		         b
	std::cout << "\033[5;36m		         
	std::cout << "\033[5;36m		  */       
//Randomly select a banner

void banner()
{
	duthomhas::csprng rng;
        short int ta = (rng() % 5);
        ta == 1 ? banner1() : ta == 2 ? banner2() : ta == 3 ? banner3() : ta == 4 ? banner4() : ta == 5 ? banner5() : banner6();
}

//Randomly create number and mixed passwords

void call(int mini, int max, short int ik)
{
	duthomhas::csprng rng;
        long long unsigned int numberofmixed;
        std::cout << std::endl;
        std::cout << "\033[1;32mPlease enter the length of the password you need \n[Max 18,446,744,073,709,551,615] \n\nBut Beware !!, this number could crash your system after a few lakhs\nDEPENDS UPON YOUR SYSTEM\033[0m\n";
	std::cout << std::endl;
	if (!(std::cin >> numberofmixed))
	{
	    throw std::invalid_argument("Please enter upto 18,446,744,073,709,551,615");
	}
        std::string mixed;
        for (long long unsigned int fromnoofall = 1; fromnoofall <= numberofmixed; ++fromnoofall)
        {
                char mixedadd = (rng() % (max - mini)) + mini;
                mixed.push_back(mixedadd);
        }
        writetofile(mixed, ik);
        startup();
}

//Randomly create a Alphabet only password

void alphaonlyfn()
{
			duthomhas::csprng rng;
                        int numberof;
                        std::cout << std::endl;
                        std::cout << "\033[1;32mPlease enter the length of the password you need\n[Max 18,446,744,073,709,551,615]\nBut Beware !!, this number could crash your system after a few lakhs\nDEPENDS UPON YOUR SYSTEM \033[0m\n\n";
                        std::cin >> numberof;
                        std::string allalpha;
                        for (long long unsigned int fromnoof = 1; fromnoof <= numberof; ++fromnoof)
                        {
                                char alphaadd = (rng() % 25) + 65;
                                allalpha.push_back(alphaadd);
                        }
                        for (short int bulb = 0; bulb < numberof / 25; bulb++)
                        {
                                for (char ujk = 97; ujk <= 122; ujk++)
                                {
                                        int kgs = (rng() % allalpha.length());
                                        allalpha[kgs] = ujk;
                                }
                        }
                        writetofile(allalpha, 2);
                        startup();
}

//Making password entered invisible

std::string safeenter(){
        termios previouslyentered;
        tcgetattr(STDIN_FILENO, &previouslyentered);
        termios newlyentered = previouslyentered;
        newlyentered.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newlyentered);

        std::string pass;
        std::getline(std::cin >> std::ws, pass);
        safeenterstop();
        return pass;

}

bool aescrypt(char type,const char** pas)
{
    int passlen=0;
    FILE *infp = NULL;
    FILE *outfp = NULL;
    encryptmode_t mode=UNINIT;
    unsigned char pass_input[MAX_PASSWD_BUF];
    unsigned char pass[MAX_PASSWD_BUF];
    int file_count = 0;
    char outfile[10];
    int password_acquired = 0;
    // Initialize the output filename
             if (type == 'd') {
                if (mode != UNINIT)
                {
                    fprintf(stderr, "Error: only specify one of -d or -e\n");
                    cleanup(outfile);
                    return -1;
                }
                mode = DEC;
                }
             if (type == 'e') {
                if (mode != UNINIT)
                {
                    fprintf(stderr, "Error: only specify one of -d or -e\n");
                    cleanup(outfile);
                    return -1;
                }
                mode = ENC;
                }
             if (!(*pas == "0")){
                if (password_acquired)
                {
                    fprintf(stderr, "Error: password supplied twice\n");
                    cleanup(outfile);
                    return -1;
                }
                    passlen = passwd_to_utf16(  (unsigned char*) *pas,
                                                strlen((char *) *pas),
                                                MAX_PASSWD_LEN,
                                                pass);
                    if (passlen < 0)
                    {
                        cleanup(outfile);
                        return -1;                    }
                    password_acquired = 1;
                }

    if (mode == UNINIT)
    {
        fprintf(stderr, "Error: -e or -d not specified\n");
        cleanup(outfile);
        return -1;
    }

    // Prompt for password if not provided on the command line
    if (passlen == 0)
    {
        passlen = read_password(pass_input, mode,1);

        switch (passlen)
        {
            case 0: //no password in input
                fprintf(stderr, "Error: No password supplied.\n");
                cleanup(outfile);
                return -1;
            case AESCRYPT_READPWD_FOPEN:
            case AESCRYPT_READPWD_FILENO:
            case AESCRYPT_READPWD_TCGETATTR:
            case AESCRYPT_READPWD_TCSETATTR:
            case AESCRYPT_READPWD_FGETC:
            case AESCRYPT_READPWD_TOOLONG:
                fprintf(stderr, "Error in read_password: %s.\n",
                        read_password_error(passlen));
                cleanup(outfile);
                return -1;
            case AESCRYPT_READPWD_NOMATCH:
                fprintf(stderr, "Error: Passwords don't match.\n");
                cleanup(outfile);
                return -1;
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
            return -1;
        }
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
        return -1;
    }
        if (mode == ENC)
        {
	  rename("Encrypted_Passwords.aes", "test.aes");
	  std::ifstream ifile;
          ifile.open("test");
	  if (ifile && rc == 1 || rc == 0){
          const char *infile;
          infile = "test";
          infp = fopen(infile, "r");
	if (infp == NULL){
	  std::cout << "\n\n\nError !! Encrypted password file is is Missing ! \n\nDid you moved a file called \"test.aes\" anywhere ?\n\n";
	  std::this_thread::sleep_for(std::chrono::milliseconds(4000));
	  return false;
	}
            if (outfp == NULL)
            {
                snprintf(outfile, 1024, "%s.aes", infile);
                if ((outfp = fopen(outfile, "w")) == NULL)
                {
                    if ((infp != stdin) && (infp != NULL))
                    {
                        fclose(infp);
                    }
                    fprintf(stderr, "Error opening output file %s : ", outfile);
                    perror("");
                    cleanup(outfile);
                    // For security reasons, erase the password
                    memset(pass, 0, MAX_PASSWD_BUF);
                    rc = -1;
                }

            }
	}
            encrypt_stream(infp, outfp, pass, passlen);
            secdel();
	    rename("test.aes", "Encrypted_Passwords.aes");
	}
        else if (mode == DEC)
        {
	 rename("Encrypted_Passwords.aes", "test.aes");
         const char *infile;
         infile = "test.aes";
         infp = fopen(infile, "r");
	 if (infp == NULL){
         std::cout << "\n\nError !! Encrypted password file is is Missing ! \n\nDid you moved a file called \"test.aes\" anywhere ?\n\n";
         std::this_thread::sleep_for(std::chrono::milliseconds(4000));
	 return false;
          }
            if (outfp == NULL)
            {
                // assume .aes extension
                strncpy(outfile, infile, strlen(infile)-4);
                outfile[strlen(infile)-4] = '\0';
                if ((outfp = fopen(outfile, "w")) == NULL)
                {
                    if ((infp != stdin) && (infp != NULL))
                    {
                        fclose(infp);
                    }
                    fprintf(stderr, "Error opening output file %s : ", outfile);
                    perror("");
                    cleanup(outfile);
                    // For security reasons, erase the password
                    memset(pass, 0, MAX_PASSWD_BUF);
                    return -1;
                }
            }

            // should probably test against ascii, utf-16le, and utf-16be
            // encodings
            rc = decrypt_stream(infp, outfp, pass, passlen);
	    rename("test.aes", "Encrypted_Passwords.aes");
        }

        if ((infp != stdin) && (infp != NULL))
        {
            fclose(infp);
        }
        if ((outfp != stdout) && (outfp != NULL))
        {
            fclose(outfp);
        }

        // If there was an error, remove the output file
        if (0)
        {
            cleanup(outfile);
            // For security reasons, erase the password
            memset(pass, 0, MAX_PASSWD_BUF);
            return -1;
        }

        // Reset input/output file names and desriptors
        outfile[0] = '\0';
        infp = NULL;
        outfp = NULL;

    // For security reasons, erase the password
    memset(pass, 0, MAX_PASSWD_BUF);
    return true;
}

//Making options entered visible again

void safeenterstop()
{
        termios previouslyentered;
        tcgetattr(STDIN_FILENO, &previouslyentered);
        termios newlyentered = previouslyentered;
        newlyentered.c_lflag |= ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newlyentered);
}

//Advanced Options menu

void advancedoptions()
{
	std::cout << "\033c";
        banner();
        std::cout << "                Welcome to PhraseNUX\n";
        std::cout << "         ( A password manager by Tamilanth )  " << std::endl
                 << std::endl;
        smallbanner();
        std::cout << "\033[5;36m\n[1] - Change Master Password\033[0m\n";
        std::cout << "\033[5;36m[2] - Clear all Passwords\033[0m\n";
        std::cout << "\033[5;36m[3] - Move Passwords to a location\033[0m\n";
        std::cout << "\033[5;36m[4] - Add your own  Password to the Database (created by you)\033[0m\n";
        std::cout << "\033[5;36m[5] - Check for updates\e[0m\n";
	std::cout << "\033[5;36m[6] - Return to Main Menu\e[0m\n\n\n\n";
	std::string Optionadvanced;
	std::cout << "Please select your Option 1 or 2 or 3 or 4:\n";
        std::cin >> Optionadvanced;
		Optionadvanced == "1" ? changepass() : Optionadvanced == "4" ? addpassmanually() :Optionadvanced == "2" ? clearallpass() : Optionadvanced == "5" ? checkforupdates(0) : Optionadvanced == "6" ? startup() : advancedoptions();
}

//Function change the Password

void changepass()
{
		std::cout << "\033[1;31m\n\nWarning !!: Keep this password very strong and please remember this, IF YOU FORGOT THIS PASSWORD, YOU CAN'T RECOVER ANY OF YOUR PASSWORDS\033[0m\n";
		std::cout << "\033[1;32m Guide for Password creation\e[0m\n\n";
		std::cout << "\033[1;31m•You can use any ASCII valuesand DO NOT include Personal information \n•short passwords are PROHIBITED\n•Max Length 1024 characters\033[0m\n\n\n";
		std::cout << "\033[1;31m\n\nPlease Enter your current password to proceed\033[0m\n\n";
		std::string oldpass = safeenter();
		std::cout << "\033[1;31m\n\nPlease enter your new password\e[0m\n\n";
		std::string newpass = safeenter();
		if (oldpass == newpass){
		std::cout << "\033[1;31m\n\nError:!: The new and old Passwords are same !!\n\nPlease Try again\033[0m\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		changepass();
		}
		else {
        		const char *Enteredtosys = oldpass.c_str();
                	aescrypt('d', &Enteredtosys);
        		const char *Enteredtosyse = newpass.c_str();
       			aescrypt('e', &Enteredtosyse);
			system("echo \"\e[92;5;12mSucess!  Password Changed, returning to Home \e[0m\n\"");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
               		startup();
			}
}

//Function accept user's own passwords

void addpassmanually(){
		std::cout << "\033[1;32m\n\nPlease enter your own passsword\033[0m\n\n";
		std::string ownpass;
		std::getline(std::cin >> std::ws, ownpass);
		std::cout << "\033[5;36m\nEnter Your Password:\033[0m\n";
        	std::string passwd = safeenter();
        	std::string tag;
        	std::cout << "\033[5;36m\nPlease enter the name for this password, so you can identify the passwords with names when you decrypt your passwords\033[0m\n";
        	std::getline(std::cin >> std::ws, tag);
        	std::cout << "\n";
        	if(veripassford(passwd)){
 		std::ofstream ifile("test");
	       	std::string writinginput = ownpass + "|-------------|" + tag;
        	ifile << writinginput <<  std::endl;
        	ifile.close();
        	veripassfore(passwd);
        	passwd = "izsywiabhaishsiwywoanshs";
	      	secdel();
		startup();
		}
		else {
		std::cout << "\033[1;31mError:!: Incorrect Password or the password file is altered\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			secdel();
                        startup();
		}
}

//delete all passwords in stored

void clearallpass()
{
		const char* pass = "0";
                aescrypt('d', &pass);
		std::ifstream fortest;
  		fortest.open("test");
 		if(fortest && rc == 1 || rc == 0) {
			fortest.close();
			aescrypt('d', &pass);
			secdel();
      			std::ofstream output("Hi");
			aescrypt('e', &pass);
			secdel();
			startup();
   		} else {
      			std::cout << "\033[1;31mError:!: Incorrect Password or the password file is altered\033[0m\n\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			startup();
   		}
}

std::string pwdfile(std::string filename1)
{
		std::string path = get_current_dir_name();
	        char finalletter = path[path.length() -1 ];
    		if(finalletter == '/'){
        	path = path + filename1;
	    	}
    		else
		{
        		path  = path + "/" + filename1;
    		}
		return path;
}



//Function to show all passwords stored

void showpass(bool what)
{
        std::ifstream ifile;
   	ifile.open("test");
   	if(ifile) {
		std::string lineofthefile;
		std::ifstream passfile(pwdfile("test"));
		unsigned long long int waitfor = 10;
		std::cout << std::endl << std::endl << std::endl;
		while(getline(passfile, lineofthefile))
        	{
                std::cout << lineofthefile <<  std::endl << std::endl;
		if (lineofthefile.length() <= 100 ) {
		unsigned int count99 = 1;
		waitfor = count99++ * 2 + waitfor;
		}
		else {
		if (lineofthefile.length() <= 1000 && lineofthefile.length() >= 101){
		unsigned int  count1001 = 1;
		waitfor = count1001++ * 4 + waitfor;
		}
		else {
		if (lineofthefile.length() >= 1001 && lineofthefile.length() <= 50000){
		unsigned int count10001 = 1;
		waitfor = count10001++ * 20 + waitfor;
		}
		else {
		unsigned int countmore = 1;
		waitfor = countmore++ * 100 + waitfor;
		}
		}
		}
		}
        	passfile.close();
		ifile.close();
		if (what){
		secdel();
		if (waitfor > 10){
		waitfor = waitfor - 10;
		waitup(waitfor);
		}
		else {
      		std::cout << "Your Password is correct but\n\nNo Passwords Found\n\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
}

		else {
		std::cout << "\033[1;31mError:!: Incorrect Password or the password file is altered\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        startup();
                }
		}
}
void checkforupdates(bool start)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://tamilanth.github.io/PhraseNUX/");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if (readBuffer == "No Updates Available\n" || readBuffer == "Latest version = 1\n" || readBuffer == ""){
    if (!start){
    std::cout << "\033[1;32m              Version is Up-to-date.....   Returning To Home Now\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    startup();
    }
    else {
	startup();
	}
    }
    else {
    std::cout << "\033[1;36m               Newer Update available !!\033[0m\n\n\n";
    std::cout << "\033[1;32mWould you like to update the program ?\033[0m\n\n";
    std::cout << "\033[5;36m[1] - Update to the newest version (Recommended\033[0m\n";
    std::cout << "\033[5;36m[2] - Don't update Return to Home\033[0m\n\n";
    short int a;
    std::cin >> a;
    if (a == 1){
    system("bash update");
    }
    else if (a == 2){
    startup();
    }
    else {
    std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n\n";
    checkforupdates(0);
    }
  }
}
}
