#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <thread>
#include "../random/csprng.hpp"
#include "../hash/sha3.h"
#include <filesystem>


unsigned long long int randomize()
{
	duthomhas::csprng rng;
        unsigned long long int b = 9999 * 99999 * (rng() % 999999999999999999);
        return b;
}

std::string str(unsigned long long int i)
{
	duthomhas::csprng rng;
        std::string x = std::to_string(i);
        return x;
}
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
void veripassford(std::string passstr);
void startup();
void secdel();
void banner();
void alphaonlyfn();
void call(int mini, int max, short int ik);
void smallbanner();
std::string pwdfile(std::string filename1);
void delpass()
{
        std::string line;
	std::cout << std::endl;
        system("echo \"\e[38;5;51mEnter Your Password:\e[0m\n\"");
        std::string lll = safeenter();
        veripassford(lll);
        //system("cat test");
	showpass(0);
        secdel();
	std::cout << std::endl << std::endl;
	std::ifstream fortest1;
	veripassford(lll);
        fortest1.open("test");
        if(fortest1) {
	secdel();
        std::string deletethis;
	system("echo \"\e[38;5;51mEnter the password (with tags) to be deleted\e[0m\"");
        std::cin >> deletethis;
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
	else {
                        system("echo \"\e[38;5;9m\n\nError:!: Incorrect Password or the password file is altered\e[0m\n\"");
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        startup();
                }

}

void writetofile(std::string ea, short int opt)
{
        std::string lll;
        std::cout << std::endl;
        std::cout << ea << std::endl << std::endl;
        system("echo \"\e[38;5;12mCan we save this password ?, if not you can generate the password again without saving this\e[0m\n\"");
        system("echo \"\e[38;5;51m[1] - Save the password \e[0m\"");
        system("echo \"\e[38;5;51m[2] - Generate a password again \e[0m\n\"");
        short int optionsforsaving;
        std::cin >> optionsforsaving;
        std::cout << "\n";
        if(optionsforsaving == 1){
        system("echo \"\e[38;5;51m\nEnter Your Password:\e[0m\"");
        lll = safeenter();
        std::string tag;
        system("echo \"\e[38;5;51m\nPlease enter the name for this password, so you can identify the passwords with names when you decrypt the passwords:\e[0m\n\n\"");
        std::cin >> tag;
        std::cout << "\n";
        veripassford(lll);
        std::ofstream file;
        file.open("test", std::ios_base::app);
        std::string writinginput = ea + "-------" + tag + "\n";
        file << writinginput;
        file.close();
        veripassfore(lll);
        lll = "00000000teidhsjgsksgsizsywiabhaishsiwywoanshs";
        secdel();
        }
        else {
                if (optionsforsaving == 2){
                        opt == 1 ? call(48, 57, 1) : opt == 2 ? alphaonlyfn() :  call(33, 126, 3);
                		          }
		else {
			system("echo \"\e[38;5;9m\n\nError:!: Please select 1 or 2 or 3 or 4\e[0m\n\"");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
       			 system("clear");
                }			}
}
void optionsB()
{       std::cout << std::endl;
        system("echo  \"\e[38;5;51m[1] - Numbers Only Mode \e[0m\"");
        system("echo  \"\e[38;5;51m[2] - Alphabets Only Mode \e[0m\"");
        system("echo  \"\e[38;5;51m[3] - Mixed Mode \e[0m\"");
        system("echo  \"\e[38;5;51m[4] - Main Menu \e[0m\n\"");
}
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
      std::cerr << "Error ! Cannot open " << filen << "" << std::endl;
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
void optionsA()
{
        system("clear");
        banner();
        std::cout << "                Welcome to PhraseNUX\n";
        std::cout << "         ( A password manager by Tamilanth )  " << std::endl
                 << std::endl;
        smallbanner();
        system("echo \"\e[38;5;51m[1] - Show Saved Passwords\e[0m\"");
        system("echo  \"\e[38;5;51m[2] - Create a  New Password\e[0m\"");
        system("echo  \"\e[38;5;51m[3] - Delete a Password\e[0m\"");
        system("echo  \"\e[38;5;51m[4] - Exit\e[0m\"");
	system("echo \"\e[38;5;51m[5] - Advanced\e[0m\n\n\n\"");
}
void waitup(int a)
{
        std::string jk = str(a);
        std::string see = "echo \"\e[38;5;9m\n\nNote: For security reasons your terminal will be cleared in " + jk + " seconds\e[0m\n\"";
        const char *hee = see.c_str();
        system(hee);
        std::this_thread::sleep_for(std::chrono::milliseconds(a * 1000));
        system("clear");
}
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
                system("exit");
        }
        else {

        if (Jj == "2")
        {//	selectservice();
                optionsB();
                std::string Option;
                std::cin >> Option;
                Option == "1" ? call(48, 57, 1) : Option == "2" ? alphaonlyfn() :  Option == "3" ? call(33, 126, 3) : Option == "4" ?  startup() :  startup();
        }
        else {

        if (Jj == "Decrypt" || Jj == "decrypt" || Jj == "D" || Jj == "d" || Jj == "1" || Jj == "DECRYPT")
        {
		std::cout << std::endl;
                system("aescrypt -d test.aes");
		showpass(1);
		std::cout << std::endl;
                secdel();
                startup();
        }
        else {	if (Jj == "5") {
			advancedoptions();
				}
		else {
                system("echo \"\e[38;5;9m\n\nError:!: Please select 1 or 2 or 3 or 4\e[0m\n\"");
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                startup();
			}
                }
                }
                }
        }
}
int main()
{
//if(checkformodification("start", "10a72e2e389ab6d338e417d87dcaa67f9bb804ff40e9ba7ccf120a2dc0bb6820") && checkformodification("install_dependencies.cpp", "185e1ec2fcb6d36b9a44571b3fa0fb354c430fbf631a015b46d411ca7c3dedb4") && checkformodification("../random/csprng.cpp", "8b409deb0f2e086d00c99d2765dd56713bb33d16c675d12fe5c6903c35d50989") && checkformodification("../random/csprng.h", "c3e5389b011088b5e5ab6c68c08cc3b952215bd52c7a28968b74c993d626afe2") && checkformodification("../random/csprng.hpp", "1cb15d8415a63fce15cc85ddcd15666973e2fb41c4edfbd3b11503ced6ba589e") && checkformodification("../random/is_iterable.hpp", "4ab295afd50988c2562d89362ae7deaf91653c5d997258525396e61bf7cc96e5") && checkformodification("../hash/sha3.cpp", "8c070dbc66dee46ce8340a6c83264c922199e51ebabbc675ea0bb08301bab7fa") &&  checkformodification("../hash/sha3.h", "302478a22134b2eb1a598cd48d331fe80c4233d3dbe90a8508ff200477e73503"))
//{
        startup();
        return 0;
//}
//else {
//exit(1);
//}
}
void veripassford(std::string passstr)
{
        std::string strrr = "aescrypt -d -p " + passstr + " test.aes";
        const char *Opennn = strrr.c_str();
        system(Opennn);
        passstr = "iyinaishsiwywoanshs";
}
void veripassfore(std::string parssstr)
{
        std::string stsrrr = "aescrypt -e -p " + parssstr + " test";
        const char *Starboy = stsrrr.c_str();
        system(Starboy);
        parssstr = "8jgftjjnshs";
        secdel();
}
void writetofileforsd(std::string dea)
{
        for (short int hhh = 0; hhh <= 20; hhh++)
        {
                std::ofstream file;
                file.open("test");
                file << dea;
                file.close();
        }
}
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
void smallbanner()
{
        system("echo \"\e[38;5;51m                ▁▂▄▅▆▇█ ƬΛ █▇▆▅▄▂▁         \e[0m\n\n\"");
}

void banner1()
{
        system("echo \"\e[38;5;9m\n\n\"");
        system("echo \"\e[38;5;9m                  ________________\"");
        system("echo \"\e[38;5;9m                 |__   __|(  ___  )\"");
        system("echo \"\e[38;5;9m                    ) (   | (   ) |\"");
        system("echo \"\e[38;5;9m                    | |   | (___) |\"");
        system("echo \"\e[38;5;9m                    | |   |  ___  |\"");
        system("echo \"\e[38;5;9m                    | |   | (   ) |\"");
        system("echo \"\e[38;5;9m                    | |   | )   ( |\"");
        system("echo \"\e[38;5;9m                    )_(   |_|   |_|\e[0m\n\n\n\n\"");
}

void banner2()
{
        system("echo \"\e[38;5;51m\n\n\"");
        system("echo  \"\e[38;5;51m                  |''||''|     |\"");
        system("echo  \"\e[38;5;51m                     ||       |||\"");
        system("echo  \"\e[38;5;51m                     ||      |  ||\"");
        system("echo  \"\e[38;5;51m                     ||     .''''|.\"");
        system("echo  \"\e[38;5;51m                    .||.   .|.  .||.\e[0m\n\n\n\n\"");
}

void banner3()
{
        system("echo \"\e[38;5;51m\n\n\"");
        system("echo  \"\e[38;5;51m                     ╭━━━━┳━━━╮     \"");
        system("echo  \"\e[38;5;51m                     ┃╭╮╭╮┃╭━╮┃     \"");
        system("echo  \"\e[38;5;51m                     ╰╯┃┃╰┫┃╱┃┃    \"");
        system("echo  \"\e[38;5;51m                     ╱╱┃┃╱┃╰━╯┃    \"");
        system("echo  \"\e[38;5;51m                     ╱╱┃┃╱┃╭━╮┃    \"");
        system("echo  \"\e[38;5;51m                     ╱╱╰╯╱╰╯╱╰╯    \e[0m\n\n\n\"");
}

void banner()
{
	duthomhas::csprng rng;
        short int ta = (rng() % 3);
        ta == 1 ? banner1() : ta == 2 ? banner2() : banner3();
}

void call(int mini, int max, short int ik)
{
	duthomhas::csprng rng;
        long long unsigned int numberofmixed;
        std::cout << std::endl;
        system("echo \"\e[92;5;12mPlease enter the length of the password you need \n[Max 18,446,744,073,709,551,615] \nBut Beware !!, this number could crash your system after a few lakhs\nDEPENDS UPON YOUR SYSTEM\e[0m\"");
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

void alphaonlyfn()
{
			duthomhas::csprng rng;
                        int numberof;
                        std::cout << std::endl;
                        system("echo \"\e[92;5;12mPlease enter the length of the password you need\n[Max 18,446,744,073,709,551,615]\nBut Beware !!, this number could crash your system after a few lakhs\nDEPENDS UPON YOUR SYSTEM \e[0m\n\"");
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

std::string safeenter()
{
        termios previouslyentered;
        tcgetattr(STDIN_FILENO, &previouslyentered);
        termios newlyentered = previouslyentered;
        newlyentered.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newlyentered);

        std::string pass;
        std::cin >> pass;
        safeenterstop();
        return pass;

}

void safeenterstop()
 {
        termios previouslyentered;
        tcgetattr(STDIN_FILENO, &previouslyentered);
        termios newlyentered = previouslyentered;
        newlyentered.c_lflag |= ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newlyentered);
}

void advancedoptions()
{
system("clear");
        banner();
        std::cout << "                Welcome to PhraseNUX\n";
        std::cout << "         ( A password manager by Tamilanth )  " << std::endl
                 << std::endl;
        smallbanner();
        system("echo \"\e[38;5;51m[1] - Change Master Password\e[0m\"");
        system("echo  \"\e[38;5;51m[2] - Clear all Passwords\e[0m\"");
        system("echo  \"\e[38;5;51m[3] - Move Passwords to a location\e[0m\"");
        system("echo  \"\e[38;5;51m[4] - Add your own  Password to the Data (created by you)\e[0m\"");
        system("echo \"\e[38;5;51m[5] - Advanced\e[0m\n\n\n\"");
	std::string Optionadvanced;
        std::cin >> Optionadvanced;
	Optionadvanced == "1" ? changepass() : Optionadvanced == "4" ? addpassmanually() :Optionadvanced == "2" ? clearallpass() : advancedoptions();
}
void selectservice()
{       std::cout << std::endl;
system("echo  \"\e[38;5;51m               [1] - Generate Manually \e[0m\n\n\n\"");

system("echo \"\e[92;5;12m                 Social Networks\e[0m\n\"");
std::cout << " [2] - Instagram                        |    ";
std::cout << " [3] - Facebook\n";
std::cout << " [4] - Twiitter                         |    ";
std::cout << " [5] - Reddit\n";
std::cout << " [6] - Telegram                         |    ";
std::cout << " [7] - Koo\n";
std::cout << " [8] - Cybernity                        |    ";
std::cout << " [9] - Houdo\n";
std::cout << "[10] - Snapchat                         |    ";
std::cout << "[11] - Sharechat\n\n";

system("echo \"\e[92;5;12m                  Productivity\e[0m\n\"");
std::cout << "[12] - Sololearn                        |    ";
std::cout << "[13] - Canva\n";
std::cout << "[14] - Adobe                            |    ";
std::cout << "[15] - Enki (Learn to code)\n";
std::cout << "[16] - Mimo (Learn python and web dev)  |    ";
std::cout << "[17] - GitHub\n";
std::cout << "[18] - Gitlab\n\n";

system("echo \"\e[92;5;12m                   Music\e[0m\n\"");
std::cout << "[19] - Spotify                          |    ";
std::cout << "[20] - Gaana\n";
std::cout << "[21] - Hungama                          |    ";
std::cout << "[22] - Jiosaavn\n";
std::cout << "[23] - Wynk                             |    ";
std::cout << "[24] - Pandora\n";
std::cout << "[24] - Deezer                           |    ";
std::cout << "[] - Last.fm\n\n";

system("echo \"\e[92;5;12m                   Private Messenger\e[0m\n\"");
std::cout << "[25] - Signal PIN                       |    ";
std::cout << "[26] - Briar Messenger\n";
std::cout << "[27] - Element Messenger                |    ";
std::cout << "[28] - Session Messenger\n";
std::cout << "[29] - Whatsapp PIN\n\n";

system("echo \"\e[92;5;12m                 Mail & others\e[0m\n\"");
std::cout << "[] - Protonmail                         |     ";
std::cout << "[] - Protonmail Mailbox\n";
std::cout << "[] - Tutanota                           |     ";
std::cout << "[] - Google\n";
std::cout << "[] - Yahoo                              |     ";
std::cout << "[] - Apple ID\n";
std::cout << "[] - Amazon\n\n\n";




}
void changepass()
{
		system("echo \"\e[38;5;9m\n\nWarning !!: Keep this password very strong and please remember this, IF YOU FORGOT THIS PASSWORD, YOU CAN'T RECOVER ANY OF YOUR PASSWORDS\e[0m\n\"");
		system("echo \"\e[92;5;12m Guide for Password creation\e[0m\n\"");
		system("echo \"\e[38;5;9m•PLEASE DONOT INCLUDE ANY SPACES IN  YOUR PASSWORD AND DONOT INCLUDE ANY SYMBOLS OTHER THAN @•_., IF YOU INCLUDE THEN YOU WILL FACE SOME TROUBLES\e[0m\n\"");
		system("echo \"\e[38;5;9m•You can use any ASCII (except  symbols) and DO NOT include Personal information and short passwords are PROHIBITED\e[0m\n\n\n\"");
		system("echo \"\e[38;5;9m\n\nPlease Enter your current password to proceed\e[0m\n\"");
		std::string oldpass = safeenter();
		system("echo \"\e[\n\nPlease enter your new password\e[0m\n\"");
		std::string newpass = safeenter();
		if (oldpass == newpass){
		system("echo \"\e[38;5;9m\n\nError:!: The new and old Passwords are same !!\e[0m\n\"");
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		changepass();
		}
		else {
			std::string enteringtosys = "aescrypt -d -p " + oldpass + " test.aes";
        		const char *Enteredtosys = enteringtosys.c_str();
        		system(Enteredtosys);
			std::string enteringtosyse = "aescrypt -e -p " + newpass + " test";
        		const char *Enteredtosyse = enteringtosyse.c_str();
       			system(Enteredtosyse);
			system("echo \"\e[92;5;12mSucess!  Password Changed, returning to Home \e[0m\n\"");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
               		startup();
			}
}
void addpassmanually()
{
		system("echo \"\e[38;5;9m\n\nNote: Please donot enter your own passwords with spaces (The words after space will NOT be saves!\e[0m\n\"");
		system("echo \"\e[92;5;12mPlease enter your own passsword\e[0m\n\"");
		std::string ownpass;
		std::cin >> ownpass;
		system("echo \"\e[38;5;51m\nEnter Your Password:\e[0m\"");
        	std::string passwd = safeenter();
        	std::string tag;
        	system("echo \"\e[38;5;51m\nPlease enter the name for this password, so you can identify the passwords with names when you decrypt your passwords\e[0m\"");
        	std::cin >> tag;
        	std::cout << "\n";
        	veripassford(passwd);
        	std::ofstream file;
        	file.open("test", std::ios_base::app);
        	std::string writinginput = ownpass + "-" + tag;
        	file << std::endl <<  writinginput <<  std::endl;
        	file.close();
        	veripassfore(passwd);
        	passwd = "izsywiabhaishsiwywoanshs";
	      	secdel();
}
void clearallpass()
{
		system("aescrypt -d test.aes");
		std::ifstream fortest;
  		fortest.open("test");
 		if(fortest) {
			system("aescrypt -d test.aes");
			secdel();
      			system("touch test");
			system("aescrypt -e test");
			secdel();
			startup();
   		} else {
      			system("echo \"\e[38;5;9m\n\nError:!: Incorrect Password or the password file is altered\e[0m\n\"");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			startup();
   		}
}
void movefile();

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
void showpass(bool what)
{
		std::string lineofthefile;
		std::ifstream passfile(pwdfile("test"));
		unsigned long long int waitfor = 0;
		std::cout << std::endl << std::endl << std::endl;
		while(getline(passfile, lineofthefile))
        	{
                std::cout << lineofthefile <<  std::endl << std::endl;
		if (lineofthefile.length() <= 100 ) {
		if (what){
		unsigned int count99 = 1;
		waitfor = count99++ * 2 + waitfor;
		}
		}
		else {
		if (lineofthefile.length() <= 1000 && lineofthefile.length() >= 101){
		if (what){
		unsigned int  count1001 = 1;
		waitfor = count1001++ * 4 + waitfor;
		}
		}
		else {
		if (lineofthefile.length() >= 1001 && lineofthefile.length() <= 50000){
		if (what){
		unsigned int count10001 = 1;
		waitfor = count10001++ * 20 + waitfor;
		}
		}
		else {
		if (what){
		unsigned int countmore = 1;
		waitfor = countmore++ * 100 +waitfor;
		}
		}
		}
		}
		}
        	passfile.close();
		if (what){
		waitup(waitfor);
		}
}

