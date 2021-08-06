/*
PhraseNUX was created && developed && is being maintained by Prashanth(Tamilanth)
© Tamilanth
PhraseNUX is free to use and free to be modified and distributed as per the GPL License
for more information on modification and distribution, please refer to LICENSE.md
Incase of any bugs please tag me by posting "Found a Bug @MY_USWLERNAME" at
		• Instagram (@its_me_tamilanth) or
		• Twitter (@Tamilanth)
		• Tag me in PhraseNUX's github discussion
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
        if (unsigned long long int b = 9999 * 99999 * (rng() % 999999999999999999)){
        return b;
	}
	else {
	return false;
	}
}


//integer to string converter

std::string str(unsigned long long int i)
{
	duthomhas::csprng rng;
        std::string x = std::to_string(i);
        return x;
}
//Declaring all functions and checkers and variables in global scope
bool aescrypt(char type,const char** pas);
bool checkforupdates(bool start);
bool addpassmanually();
bool changeprogramcaller();
bool changepass();
bool safeenterstop();
bool selectservice();
bool advancedoptions();
std::string safeenter();
bool showpass(bool what);
void waitup(int a);
bool veripassfore(std::string passstr);
bool veripassford(std::string passstr);
bool startup();
signed int rc = 0;
signed int enrc = 0;
inline bool secdel();
void banner();
bool alphaonlyfn(bool num);
bool call(int mini, int max, short int ik);
void smallbanner();
std::string pwdfile(std::string filename1);


//function to delete passwords

bool delpass()
{
        std::string line;
	std::cout << "\n";
        std::cout << "\033[1;31mEnter Your Password:\033[0m";
        std::string lll = safeenter();
	if (!(showpass(0))){
	return false;
	}
	std::cout << "\n" << "\n";
        std::string deletethis;
	std::cout << "\033[1;31mEnter the password (with tags) to be deleted\e[0m\n";
        std::getline(std::cin >> std::ws, deletethis);
        if(!(veripassford(lll))){
	std::cout << "\033[1;31mError!! in Decrypting the Encrypted password\033[0m\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        return false;
        }
        std::ifstream oldfile("test");
        if (!oldfile.is_open())
        {
                std::cout << "\noperation failed !!!\n";
		return false;
        }
        std::ofstream newfile("testw");
        while(getline(oldfile, line))
        {
		if(line.find(deletethis) == std::string::npos){
                newfile << line << std::endl;
    		}
	}
        oldfile.close();
        newfile.close();
        if(!secdel()){
	remove("test");
	}
        rename("testw", "test");
        if(!veripassfore(lll)){
	std::cout << "\033[1;31mYour Newly Generated Password has not be saved ! Due to an error\033[0m\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	return false;
	}
        lll = "sjueodnzkslsnejsidaishsiwywoanshs";
	if (!(startup())){
	std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	return false;
	}
return true;
}

//Function to write to the password file

bool writetofile(std::string ea, short int opt)
{	short int optionsforsaving;
        std::string lll;
	std::cout << "\n";
	if (ea.length() > 1000000){
	std::cout << "\033[5;36m\nLooks like the generated password is too long \033[0m\n";
	short int moreopt;
	std::cout << "\033[5;36m\n[1] - Show Anyway\033[0m";
	std::cout << "\033[5;36m\n[2] - Directly save to enecrypted password file\033[0m\n";
        std::cout << "\n";
	std::cin >> moreopt;
	if (moreopt == 1){
	std::cout << "\n";
        std::cout << ea << std::endl << "\n";
        std::cout << "\033[1;34mCan we save this password ?, if not you can generate the password again without saving this\033[0m\n\n";
        std::cout << "\033[1;36m[1] - Save the password \033[0m\n";
        std::cout << "\033[1;36m[2] - Generate a password again \033[0m\n\n";
        std::cin >> optionsforsaving;
        std::cout << "\n";
        }
	else if (moreopt == 2){
	optionsforsaving = 1;
	}
	else {
	std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                                        std::cout << "\033c";
                                        system("clear");
                                        return false;
	}
	}
	else {
	std::cout << "\n";
        std::cout << ea << std::endl << "\n";
        std::cout << "\033[1;34mCan we save this password ?, if not you can generate the password again without saving this\033[0m\n\n";
        std::cout << "\033[1;36m[1] - Save the password \033[0m\n";
        std::cout << "\033[1;36m[2] - Generate a password again \033[0m\n\n";
        std::cin >> optionsforsaving;
        std::cout << "\n";
	}
        if(optionsforsaving == 1){
        std::cout << "\033[1;31mEnter Your Password:\033[0m";
        lll = safeenter();
	std::string tag;
        std::cout << "\033[5;36m\n\nPlease enter the name for this password, so you can identify the passwords with names when you decrypt the passwords:\033[0m\n\n\n";
	std::getline(std::cin >> std::ws, tag);
        std::cout << "\n";
	bool a = veripassford(lll);
        if(a && rc){
	}
	else if (!a && !rc){
	for (short int count = 0; count <= 5; count++){
	if(count == 4){
        std::cout << "\033[1;31mEntered incorrect Password for 5 times exiting !\n\033[0m";
        return false;
        }
	std::cout << "\033[1;31m\nEnter Your Password:\033[0m";
	lll = safeenter();
        if(veripassford(lll)){
	break;
	}
	}
	}
	std::ofstream file;
        file.open("test", std::ios_base::app);
        std::string writinginput = ea + "|-------|A|_~`------|" + tag;
        file << writinginput << std::endl;
        file.close();
        if(!(veripassfore(lll))){
	std::cout << "\033[1;31mYour Newly Generated Password has not be saved ! Due to an error\033[0m\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	return false;
	}
        lll = "0sywwywoanshs";
        if(!secdel()){
	remove("test");
	}
	if (!(startup())){
	std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	return false;
	}
        return true;
	}
	else {

		if (optionsforsaving == 2){
			    switch (opt) {
        			case 1:
            				call(48, 57, 1);
            				break;
        			case 2:
            				alphaonlyfn(0);
            				break;
				case 3:
					alphaonlyfn(1);
					break;
        			case 4:
            				call(33, 126, 3);
            				break;
				default:
					std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n";
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));
       					std::cout << "\033c";
					system("clear");
					return false;

              }
	  }
}
return true;
}

//Function that displays the custom option banner

void optionsB()
{       std::cout << "\n";
        std::cout << "\033[5;36m[1] - Numbers Only Mode \033[0m\n";
        std::cout << "\033[5;36m[2] - Alphabets Only Mode \033[0m\n";
	std::cout << "\033[5;36m[3] - Alphabets-Numeric Mode \033[0m\n";
        std::cout << "\033[5;36m[4] - Mixed Mode \033[0m\n";
        std::cout << "\033[5;36m[5] - Main Menu \033[0m\n\n";
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
        std::cout << "         ( A password manager by Tamilanth )  " << "\n"
                 << "\n";
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
	system("clear");
}

//Function which acts like "main" function

bool startup()
{
        optionsA();
        char Jj;
        std::cout << "Please select your Option 1 or 2 or 3 or 4:\n";
        std::cin >> Jj;
        if (Jj == '3')
        {
                if(!(delpass())){
		std::cout << "\033[1;31mError!! in Deleting the passwords\033[0m\n\n";
        	return false;
		}
		if(!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
                        }
		return true;
	}

        else if (Jj == '4')
        {
                exit(1);
        }
        else if (Jj == '2')
        {
                optionsB();
                char  Option;
                std::cin >> Option;
                                if (Option == '1'){
                                        if (!(call(48, 57, 1))){
					std::cout << "\033[1;31mError!! in generating the password\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					return false;
					}
					if(!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
                        		}
					return true;
					}
                                else if (Option == '2'){
                                        if(!(alphaonlyfn(0))){
					std::cout << "\033[1;31mError!! in generating the password\033[0m\n\n";
					std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					return false;
					}
					return true;
                         		if(!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
                        		}
				        }
				else if (Option == '3'){
					if(!(alphaonlyfn(1))){
                                        std::cout << "\033[1;31mError!! in generating the password\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					return false;
					}
					if(!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
                        		}
					return true;
					}
                                else if (Option == '4'){
                                        if(!(call(33, 126, 3))){
					std::cout << "\033[1;31mError!! in generating the password\033[0m\n\n";
					std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					return false;
					}
					return true;
                                        }
                                else {
					std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                                        std::cout << "\033c";
					system("clear");
					if(!(startup())){
					std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
					std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					}
					return false;
        				}
	}
        else if (Jj == 'D' || Jj == 'd' || Jj == '1')
        {
		std::cout << "\n"  << "\n";
		showpass(1);
		if(!(startup())){
                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			return false;
		}
		return true;
        }
        else if (Jj == '5') {
		if(!(advancedoptions())){
		std::cout << "\033[1;31mError!! in starting advanced options !!\033[0m\n\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		return false;
		}
		if(!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
                        }
		return true;
		}
		else {
                std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                if(!(startup())){
		std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";	
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			return false;
			}
		return false;
		}
	return true;
}

//Main
int main()
{
//if(checkformodification("start", "10a72e2e389ab6d338e417d87dcaa67f9bb804ff40e9ba7ccf120a2dc0bb6820") && checkformodification("install_dependencies.cpp", "185e1ec2fcb6d36b9a44571b3fa0fb354c430fbf631a015b46d411ca7c3dedb4") && checkformodification("../random/csprng.cpp", "8b409deb0f2e086d00c99d2765dd56713bb33d16c675d12fe5c6903c35d50989") && checkformodification("../random/csprng.h", "c3e5389b011088b5e5ab6c68c08cc3b952215bd52c7a28968b74c993d626afe2") && checkformodification("../random/csprng.hpp", "1cb15d8415a63fce15cc85ddcd15666973e2fb41c4edfbd3b11503ced6ba589e") && checkformodification("../random/is_iterable.hpp", "4ab295afd50988c2562d89362ae7deaf91653c5d997258525396e61bf7cc96e5") && checkformodification("../hash/sha3.cpp", "8c070dbc66dee46ce8340a6c83264c922199e51ebabbc675ea0bb08301bab7fa") &&  checkformodification("../hash/sha3.h", "302478a22134b2eb1a598cd48d331fe80c4233d3dbe90a8508ff200477e73503"))
//{
	std::cout << "\033c";
	if(checkforupdates(1)){
        return 0;
	}
//else {
//exit(1);
//cout << "Some or all files are corrupted\n this could be dangerous\n";
//
//}
}

//Password verification for decryption

bool veripassford(std::string passstr)
{
	std::cout << "\n";
        const char *Opennn = passstr.c_str();
        if(!(aescrypt('d', &Opennn))){
	if(!(rc)){
	std::cout << "\033[1;31mError!! in Decrypting the Encrypted password\033[0m\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        passstr = "iyinaishsiwywoanshs";
	return false;
	}
	}
	return true;
}

//Password verification for encryption

bool veripassfore(std::string parssstr)
{
	std::ifstream ifile;
  	ifile.open("test");
   	if(!(ifile && rc)){
	std::cout << "\033[1;31mError:!: Incorrect Password or the password file is altered\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        if(!(secdel())){
                        remove("test");
                        }
           }
	ifile.close();
	std::cout << "\n";
        const char *Starboy = parssstr.c_str();
        if(!(aescrypt('e', &Starboy))){
	std::cout << "\033[1;31mError!! in Encrypting the Decrypted password\033[0m\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        parssstr = "8jgftjjnshs";
	return false;
	}
	parssstr = "8jgftjjnshs";
        if(!(secdel())){
        remove("test");
        }
                        if(!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                 	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
				        return false;
			}
	return true;
}

//Writing to file for secure delete

bool writetofileforsd(std::string dea)
{
        for (short int hhh = 0; hhh <= 35; hhh++)
        {
                std::ofstream file;
                file.open("test");
                file << dea;
                file.close();
        }
		return true;
}

//Function for secure deletion

inline bool secdel()
{
        long long unsigned int acaa = randomize();
        long long unsigned int bcbb = randomize();
        std::string aaaab = str(acaa);
        std::string baaab = str(bcbb) + aaaab;
        std::string erapt = aaaab + baaab + aaaab + baaab + aaaab + baaab + aaaab + baaab;
        if (writetofileforsd(erapt)){
        system("srm -z test");
	remove("test");
	}
	return true;
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

//Randomly select a banner

void banner()
{
	duthomhas::csprng rng;
        short int ta = (rng() % 5);
        ta == 1 ? banner1() : ta == 2 ? banner2() : ta == 3 ? banner3() : ta == 4 ? banner4() : banner5();
}

//Randomly create number and mixed passwords

bool call(int mini, int max, short int ik)
{
	duthomhas::csprng rng;
        unsigned long long int numberofmixed;
        std::cout << "\n";
        std::cout << "\033[1;32mPlease enter the length of the password you need \n[Max 18,446,744,073,709,551,615] \n\nBut Beware !!, this number could crash your system after a few lakhs\nDEPENDS UPON YOUR SYSTEM\033[0m\n";
	std::cout << "\n";
	if (!(std::cin >> numberofmixed))
	{
	    throw std::invalid_argument("Please enter upto 18,446,744,073,709,551,615");
	}
        std::string mixed;
        for (unsigned long long int fromnoofall = 1; fromnoofall <= numberofmixed; ++fromnoofall)
        {
                char mixedadd = (rng() % (max - mini)) + mini;
                mixed.push_back(mixedadd);
        }
        if(!(writetofile(mixed, ik))){
	std::cout << "\033[1;31mError!! in writing the  passwords to file\033[0m\n\n";
        return false;
	}
	if(!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        return false;
	}
	return true;
}

//Randomly create a Alphabet only && Alphabet + Number password

bool alphaonlyfn(bool num)
{
			short int type = 2;
			duthomhas::csprng rng;
                        unsigned long long int numberof;
                        std::cout << "\n";
                        std::cout << "\033[1;32mPlease enter the length of the password you need\n Literally there is no limits for the length of the password \n\nBut Beware !!, this could crash your system after a few lakhs or Crores\nDEPENDING UPON YOUR SYSTEM \033[0m\n\n";
                        std::cin >> numberof;
                        std::string allalpha;
                        for (unsigned long long int fromnoof = 1; fromnoof <= numberof; ++fromnoof)
                        {
                                char alphaadd = (rng() % 25) + 65;
                                allalpha.push_back(alphaadd);
                        }
                        for (unsigned long long int bulb = 0; bulb < numberof / 25; bulb++)
                        {
                                for (char alpha = 97; alpha <= 122; alpha++)
                                {
                                        unsigned long long int kgs = (rng() % allalpha.length());
                                        allalpha[kgs] = alpha;
                                }
                        }
			if(num){
			type = 3;
			for (unsigned long long int num1 = 0; num1 < numberof /13; num1++)
			{
				for (char num2 = 48; num2 <= 57; num2++)
				{
					unsigned long long int placenum = (rng() % allalpha.length());
					allalpha[placenum] = num2;
				}
			}
			}
                        if(!(writetofile(allalpha, type))){
			std::cout << "\033[1;31mYour Newly Generated Password has not be saved ! Due to an error\033[0m\n\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			return false;
                        }
			if(!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
                        }
	return true;
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
        if(!(safeenterstop())){
	std::cout << "\033[1;31mLooks like the invisible typing remains forever\033[0m\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
        return pass;

}

bool aescrypt(char type,const char** pas)
{
    int passlen=0;
    FILE *infp = NULL;
    FILE *outfp = NULL;
    encryptmode_t mode=UNINIT;
    unsigned char pass[MAX_PASSWD_BUF];
    char outfile[10];
    // Initialize the output filename
             if (type == 'd') {
                if (mode != UNINIT)
                {
                    fprintf(stderr, "Error: only specify one of -d or -e\n");
                    cleanup(outfile);
                    return 0;
                }
                mode = DEC;
                }
             if (type == 'e') {
                if (mode != UNINIT)
                {
                    fprintf(stderr, "Error: only specify one of -d or -e\n");
                    cleanup(outfile);
                    return 0;
                }
                mode = ENC;
                }
                    passlen = passwd_to_utf16(  (unsigned char*) *pas,
                                                strlen((char *) *pas),
                                                MAX_PASSWD_LEN,
                                                pass);
                    if (passlen < 0)
                    {
                        cleanup(outfile);
                        return 0;        
                }

    if (mode == UNINIT)
    {
        fprintf(stderr, "Error: -e or -d not specified\n");
        cleanup(outfile);
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
	  if (ifile && rc){
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
                    if (infp != NULL)
                    {
                        fclose(infp);
                    }
                    fprintf(stderr, "Error opening output file %s : ", outfile);
                    perror("");
                    cleanup(outfile);
                    // For security reasons, erase the password
                    memset(pass, 0, MAX_PASSWD_BUF);
                    rc = 0;
                }

            }
	}
            enrc = encrypt_stream(infp, outfp, pass, passlen);
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
                    if (infp != NULL)
                    {
                        fclose(infp);
                    }
                    fprintf(stderr, "Error opening output file %s : ", outfile);
                    perror("");
                    cleanup(outfile);
                    // For security reasons, erase the password
                    memset(pass, 0, MAX_PASSWD_BUF);
                    return 0;
                }
            }

            // should probably test against ascii, utf-16le, and utf-16be
            // encodings
            rc = decrypt_stream(infp, outfp, pass, passlen);
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
 return true;
}

//Making options entered visible again

bool safeenterstop()
{
        termios previouslyentered;
        tcgetattr(STDIN_FILENO, &previouslyentered);
        termios newlyentered = previouslyentered;
        newlyentered.c_lflag |= ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newlyentered);
	return true;
}

//Advanced Options menu

bool advancedoptions()
{
	std::cout << "\033c";
        banner();
        std::cout << "                Welcome to PhraseNUX\n";
        std::cout << "         ( A password manager by Tamilanth )  " << "\n"
                 << "\n";
        smallbanner();
        std::cout << "\033[5;36m\n[1] - Change Master Password\033[0m\n";
        std::cout << "\033[5;36m[2] - Add your own  Password to the Database (created by you)\033[0m\n";
        std::cout << "\033[5;36m[3] - Check for updates\e[0m\n";
	std::cout << "\033[5;36m[4] - Change the phrase to call the program\033[0m\n";
	std::cout << "\033[5;36m[5] - Return to Main Menu\e[0m\n\n\n\n";
	char Optionadvanced;
	std::cout << "Please select your Option 1 or 2 or 3 or 4:\n";
        std::cin >> Optionadvanced;
                                if (Optionadvanced ==  '1'){
                                        if(changepass()){
					return true;
					}
					else {
					return false;
					}
				}
                                else if (Optionadvanced == '2'){
                                        if(addpassmanually()){
                                        return true;
					}
					else {
					return false;
					}
					}
				else if (Optionadvanced == '4'){
					if (changeprogramcaller()){
					return true;
					}
					else {
					return false;
					}
					}
				else if (Optionadvanced == '3'){
					if(checkforupdates(0)){
					return true;
					}
					else {
					return false;
					}
					}
				else if (Optionadvanced == '5'){
					return true;
					}
                                else {
					std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                                        std::cout << "\033c";
					advancedoptions();
					return false;
}
return true;
}

//Function which changes the Password

bool changepass()
{
		std::cout << "\033[1;31m\n\nWarning !!: Keep this password very strong and please remember this, IF YOU FORGOT THIS PASSWORD, YOU CAN'T RECOVER ANY OF YOUR PASSWORDS\033[0m\n";
		std::cout << "\033[1;32m Guide for Password creation\e[0m\n\n";
		std::cout << "\033[1;31m•You can use any ASCII valuesand DO NOT include Personal information \n•short passwords are PROHIBITED\n•Max Length 1024 characters\033[0m\n\n\n";
		std::cout << "\033[1;31m\n\nPlease Enter your current password to proceed\033[0m";
		std::string oldpass = safeenter();
		std::cout << std::endl;
		std::cout << "\033[1;31m\n\nPlease enter your new password  \e[0m";
		std::string newpass = safeenter();
		if (oldpass == newpass){
		std::cout << "\033[1;31m\n\nError:!: The new and old Passwords are same !!\n\nPlease Try again  \033[0m\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		if(!changepass()){
		return false;
		}
		else{
		return true;
		}
                }
		else {
                	if (!veripassford(oldpass)){
			std::cout << "\033[1;31mError!! in Decrypting the Encrypted password\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                        return false;
                        }
       			if (!veripassfore(newpass)){
			std::cout << "\033[1;31mYour Newly Generated Password has not be saved ! Due to an error\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                        return false;
                        }
			std::cout << "Success! password changed successfully\033[0m\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
               		return true;
			}
return true;
}

//Function which accepts user's own passwords

bool addpassmanually(){
		std::cout << "\033[1;32m\n\nPlease enter your own passsword\033[0m\n\n";
		std::string ownpass;
		std::getline(std::cin >> std::ws, ownpass);
		std::cout << "\033[5;36m\nEnter Your Password:\033[0m";
        	std::string passwd = safeenter();
        	std::string tag;
        	std::cout << "\033[5;36m\n\n\nPlease enter the name for this password, so you can identify the passwords with names when you decrypt your passwords\033[0m\n";
        	std::getline(std::cin >> std::ws, tag);
        	std::cout << "\n";
        	if(!(veripassford(passwd))){
		std::cout << "\033[1;31mError!! in Decrypting the Encrypted password\033[0m\n\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                return false;
                }
 		std::ofstream ifile;
		ifile.open("test", std::ios_base::app);
	       	std::string writinginput = ownpass + "|-------|A|_~`------|" + tag;
        	ifile << writinginput << std::endl;
        	ifile.close();
        	if(!(veripassfore(passwd))){
		passwd = "izsywiabhaishsiwywoanshs";
		std::cout << "\033[1;31mYour Newly Generated Password has not be saved ! Due to an error\033[0m\n\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                return false;
                }
        	passwd = "izsywiabhaishsiwywoanshs";
	      	if(!(secdel())){
		remove ("test");
		}
		return true;
}

bool nottoshowallpass = true;
std::string tagforsearch;

//Function to show passwords stored

bool showpass(bool what)
{
	std::cout << "\033[1;31m\nEnter Your Password:\033[0m";
	std::string lll = safeenter();
	unsigned int numpasstodisno = 0;
	for (unsigned int numpasstodis = 1; numpasstodis < 8; numpasstodis++){
	if (!veripassford(lll)){
	std::cout << "\033[1;31mError!! in Decrypting the Encrypted password\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                        return false;
                        }
        std::ifstream ifile;
   	ifile.open("test");
   	if(!(ifile && rc)) {
	std::cout << "\033[1;31mError!! in Decrypting the Encrypted password\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                        return false;
        		}
		ifile.close();
		if(!(secdel())){
                remove ("test");
                }
		std::string lineofthefile;
		unsigned int waitfor = 10;
		if(nottoshowallpass){
		std::cout << "\033[5;36m\n\nPlease Enter the keyword of the password you need\033[0m\n\n";
		std::getline(std::cin >> std::ws, tagforsearch);
		}
		std::cout << "\n" << "\n" << "\n";
		if (!veripassford(lll)){
        	std::cout << "\033[1;31mError!! in Decrypting the Encrypted password\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                        return false;
                        }
		std::ifstream passfile("test");
		while(getline(passfile, lineofthefile))
        	{
		if(lineofthefile.find(tagforsearch) != std::string::npos){
		    numpasstodisno++;
		    for (auto ai = lineofthefile.length() - 1; ai >= 0; ai--){
	            if (lineofthefile[ai] == '|' && lineofthefile[ai - 1] == '-' && lineofthefile[ai - 2] == '-' && lineofthefile[ai - 3] == '-' && lineofthefile[ai - 4] == '-' && lineofthefile[ai - 5] == '-' && lineofthefile[ai - 6] == '-' && lineofthefile[ai - 7] == '`' && lineofthefile[ai - 8] == '~' && lineofthefile[ai - 9] == '_' && lineofthefile[ai - 10] == '|' && lineofthefile[ai - 11] == 'A' && lineofthefile[ai - 12] == '|' && lineofthefile[ai - 13] == '-' && lineofthefile[ai - 14] == '-' && lineofthefile[ai - 15] == '-' && lineofthefile[ai - 16] == '-' && lineofthefile[ai - 17] == '-' && lineofthefile[ai - 18] == '-' &&  lineofthefile[ai - 19] == '-' && lineofthefile[ai - 20] == '|'){
		            auto I = lineofthefile.length() - ai + 20;
			    std::string tagfromfile;
			    for (auto tagpos = ai + 1; tagpos < lineofthefile.length(); tagpos++){
			    tagfromfile.push_back(lineofthefile[tagpos]);
			    }
			    lineofthefile.resize(lineofthefile.size() - I);
			    std::cout << tagfromfile + " 👇" << "\n" << "\n" << lineofthefile << "\n" << "\n" << "\n" << "\n" << "\n";
			    break;

        			    }
		}
		if (lineofthefile.length() <= 100 ) {
		unsigned int count99 = 1;
		waitfor = count99++ * 2 + waitfor;
		}
		else if (lineofthefile.length() <= 1000 && lineofthefile.length() >= 101){
		unsigned int  count1001 = 1;
		waitfor = count1001++ * 4 + waitfor;
		}
		else if (lineofthefile.length() >= 1001 && lineofthefile.length() <= 50000){
		unsigned int count10001 = 1;
		waitfor = count10001++ * 20 + waitfor;
		}
		else {
		unsigned int countmore = 1;
		waitfor = countmore++ * 100 + waitfor;
		}}}
        	passfile.close();
		if (what){
		if(!(secdel())){
                remove ("test");
                }
		if (waitfor > 10){
		waitfor = waitfor - 10;
		waitup(waitfor);
		return true;
		}
		else if (waitfor <= 10){
		std::cout << "\033[1;31mThe Tag you entered does not match any passwords\033[0m\n\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		if (numpasstodis == 5){
		std::cout << "\033[1;31mLooks like the Tag which you entered does not match any passwords for 5 times\033[0m\n\n";
		std::cout << "\033[5;36m[1] - Try entering again\033[0m\n";
    		std::cout << "\033[5;36m[2] - Show all passwords\033[0m\n\n";
		char optionsforshow;
		std::cin >> optionsforshow;
		if(optionsforshow == '1'){
		numpasstodis = 1;
		continue;
		}
		else if(optionsforshow == '2'){
		nottoshowallpass = false;
		tagforsearch = "|";
		}}}
		else {
		std::cout << "\033[1;31mError:!: Incorrect Password or the password file is altered\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        startup();
			return false;
			}}}
	return true;
}

//Function which checks for updates

bool checkforupdates(bool start)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://tamilanth.github.io/PhraseNuX/main/updates/");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    if (res){
    std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
   }
    curl_easy_cleanup(curl);
    if (readBuffer == "No Updates Available\n" || readBuffer == "1\n" || readBuffer == "" || readBuffer == "1" || readBuffer == "No Updates Available"){
    if (!start){
    std::cout << "\033[1;32m              Version is Up-to-date.....   Returning To Home Now\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    if (!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
                        }
    }
    else if (start){
		if (!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
                        }
	return true;
}
    }
    else {
    std::cout << "\033[1;36m               Newer Update available !!\033[0m\n\n\n";
    std::cout << "\033[1;32mWould you like to update the program ?\033[0m\n\n";
    std::cout << "\033[5;36m[1] - Update to the newest version (Recommended)\033[0m\n";
    std::cout << "\033[5;36m[2] - Don't update Return to Home\033[0m\n\n";

  CURL *curl2;
  CURLcode res2;
  std::string readBuffer2;

  curl2 = curl_easy_init();
  if(curl2) {
    curl_easy_setopt(curl2, CURLOPT_URL, "https://tamilanth.github.io/PhraseNuX/main/changelog/");
    curl_easy_setopt(curl2, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl2, CURLOPT_WRITEDATA, &readBuffer2);
    res2 = curl_easy_perform(curl2);
    if (res2){
    std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
   }
    curl_easy_cleanup(curl2);
    std::cout <<"\033[1;36m" << readBuffer2<< "\033[0m\n" << std::endl;
 }
    short int a;
    std::cin >> a;
    if (a == 1){
    if(!(system("bash update"))){
    std::cout << "\033[1;31mError!! could not start the update script, please do it manually by running \"bash update\" in you terminal\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                        return false;
                        }
    return true;
    }
    else if (a == 2){
    if(!(startup())){
                                        std::cout << "\033[1;31mError!! in starting the program !!\033[0m\n\n";
                                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                        return false;
                        }
    return true;
    }
    else {
    std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n\n";
    if(!(checkforupdates(0))){
    std::cout << "\033[1;31mError!! could not start the update script, please do it manually by running \"bash update\" in you terminal\033[0m\n\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                        return false;
                        }
    return false;
    }
  }

}
return true;
}

//Function to change the function which calls the program

bool changeprogramcaller()
{
		std::cout << "\033[5;36m\nPlease Enter your current word which calls the program\033[0m\n";
		std::string callname;
		std::cin >> callname;
		std::ifstream shfile;
		shfile.open ("/usr/bin/" + callname);
		if(!shfile){
		std::cout << "\033[1;31m\n\nLooks like there is no call file like that\033[0m\n\n";
		std::cout << "\033[5;36m[1] - Try entering again\033[0m\n";
		std::cout << "\033[5;36m[2] - Create a call function\033[0m\n\n\n";
		char optionforprogramcaller;
		std::cin >> optionforprogramcaller;
		if (optionforprogramcaller == '1'){
		changeprogramcaller();
		}
		else if(optionforprogramcaller == '2'){
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
		callname = "chmod u=x /usr/bin/" + callname;
		const char* nnamee = callname.c_str();
		system(nnamee);
		return true;
		}
		}
		else{
		shfile.close();
		std::cout << "\033[5;36m\nPlease Enter your new word which will be used to calls the program\033[0m\n";
		std::string newcallname;
		std::cin >> newcallname;
		newcallname = "/usr/bin/" + newcallname;
		callname = "/usr/bin/" + callname;
		rename(callname.c_str(), newcallname.c_str());
		return true;
		}
return true;
}
