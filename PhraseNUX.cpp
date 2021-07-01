#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <thread>
#include "csprng.hpp"

using namespace std;

unsigned long long int randomize()
{
	duthomhas::csprng rng;
        unsigned long long int b = 9999 * 99999 * (rng() % 999999999999999999);
        return b;
}

string str(unsigned long long int i)
{
	duthomhas::csprng rng;
        string x = to_string(i);
        return x;
}
void clearallpass();
void addpassmanually();
void changepass();
void safeenterstop();
void advancedoptions();
string safeenter();
void waitup(int a);
void veripassfore(string passstr);
void veripassford(string passstr);
void startup();
void secdel();
void banner();
void alphaonlyfn();
void call(int mini, int max, short int ik);
void smallbanner();
void delpass()
{
        string line;
        system("echo \"\e[38;5;51mEnter Your Password:\e[0m\"");
	cout << endl;
        string lll = safeenter();
        veripassford(lll);
        system("cat test");
        secdel();
        string deletethis;
        cin >> deletethis;
        veripassford(lll);
        ifstream oldfile("test");
        if (!oldfile.is_open())
        {
                cout << "\noperation failed !!!\n";
        }
        ofstream newfile("testw");
        while(getline(oldfile, line))
        {
                if (line != deletethis)
                newfile << line << endl;
        }
        oldfile.close();
        newfile.close();
        secdel();
        rename("testw", "test");
        veripassfore(lll);
        lll = "0eidhsjgsksgsizsywiabhaishsiwywoanshs";
        startup();

}

void writetofile(string ea, short int opt)
{
        string lll;
        cout << endl;
        cout << ea << endl << endl;
        system("echo \"\e[38;5;12mCan we save this password ?, if not you can generate the password again without saving this\e[0m\n\"");
        system("echo \"\e[38;5;51m[1] - Save the password \e[0m\"");
        system("echo \"\e[38;5;51m[2] - Generate a password again \e[0m\n\"");
        short int optionsforsaving;
        cin >> optionsforsaving;
        cout << "\n";
        if(optionsforsaving == 1){
        system("echo \"\e[38;5;51m\nEnter Your Password:\e[0m\"");
        lll = safeenter();
        string tag;
        system("echo \"\e[38;5;51m\nPlease enter the name for this password, so you can identify the passwords with names when you decrypt the passwords:\e[0m\n\n\"");
        cin >> tag;
        cout << "\n";
        veripassford(lll);
        ofstream file;
        file.open("test", ios_base::app);
        string writinginput = ea + "-" + tag;
        file << endl <<  writinginput <<  endl;
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
			this_thread::sleep_for(chrono::milliseconds(1000));
       			 system("clear");
                }			}
}
void optionsB()
{       cout << endl;
        system("echo  \"\e[38;5;51m[1] - Numbers Only Mode \e[0m\"");
        system("echo  \"\e[38;5;51m[2] - Alphabets Only Mode \e[0m\"");
        system("echo  \"\e[38;5;51m[3] - Mixed Mode \e[0m\"");
        system("echo  \"\e[38;5;51m[4] - Main Menu \e[0m\n\"");
}
void optionsA()
{
        system("clear");
        banner();
        cout << "                Welcome to PhraseX\n";
        cout << "         ( A password manager by Tamilanth )  " << endl
                 << endl;
        smallbanner();
        system("echo \"\e[38;5;51m[1] - Decrypt\e[0m\"");
        system("echo  \"\e[38;5;51m[2] - Create a  New Password\e[0m\"");
        system("echo  \"\e[38;5;51m[3] - Delete a Password\e[0m\"");
        system("echo  \"\e[38;5;51m[4] - Exit\e[0m\"");
	system("echo \"\e[38;5;51m[5] - Advanced\e[0m\n\n\n\"");
}
void waitup(int a)
{
        string jk = str(a);
        string see = "echo \"\e[38;5;9m\n\nNote: For security reasons your terminal will be cleared in " + jk + " seconds\e[0m\n\"";
        const char *hee = see.c_str();
        system(hee);
        this_thread::sleep_for(chrono::milliseconds(a * 1000));
        system("clear");
}
void startup()
{
        optionsA();
        string Jj;
        cout << "Please select your Option 1 or 2 or 3 or 4:\n";
        cin >> Jj;
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
        {
                optionsB();
                string Option;
                cin >> Option;
                Option == "1" ? call(48, 57, 1) : Option == "2" ? alphaonlyfn() :  Option == "3" ? call(33, 126, 3) : Option == "4" ?  startup() :  startup();
        }
        else {

        if (Jj == "Decrypt" || Jj == "decrypt" || Jj == "D" || Jj == "d" || Jj == "1" || Jj == "DECRYPT")
        {
		cout << endl;
                system("aescrypt -d test.aes");
		cout << endl;
                system("cat test");
                secdel();
                waitup(15);
                startup();
        }
        else {	if (Jj == "5") {
			advancedoptions();
				}
		else {
                system("echo \"\e[38;5;9m\n\nError:!: Please select 1 or 2 or 3 or 4\e[0m\n\"");
                this_thread::sleep_for(chrono::milliseconds(1000));
                startup();
			}
                }
                }
                }
        }
}
int main()
{
        startup();
        return 0;
}
void veripassford(string passstr)
{
        string strrr = "aescrypt -d -p " + passstr + " test.aes";
        const char *Opennn = strrr.c_str();
        system(Opennn);
        passstr = "iyinaishsiwywoanshs";
}
void veripassfore(string parssstr)
{
        string stsrrr = "aescrypt -e -p " + parssstr + " test";
        const char *Starboy = stsrrr.c_str();
        system(Starboy);
        parssstr = "8jgftjjnshs";
        secdel();
}
void writetofileforsd(string dea)
{
        for (short int hhh = 0; hhh <= 20; hhh++)
        {
                ofstream file;
                file.open("test");
                file << dea;
                file.close();
        }
}
void secdel()
{
        long long unsigned int acaa = randomize();
        long long unsigned int bcbb = randomize();
        string aaaab = str(acaa);
        string baaab = str(bcbb) + aaaab;
        string erapt = aaaab + baaab + aaaab + baaab + aaaab + baaab + aaaab + baaab;
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
        cout << endl;
        system("echo \"\e[92;5;12mPlease enter the length of the password you need \n[Max 18,446,744,073,709,551,615] \nBut Beware !!, this number could crash your system after a few lakhs\nDEPENDS UPON YOUR SYSTEM\e[0m\"");
	cout << endl;
	if (!(cin >> numberofmixed))
	{
	    throw std::invalid_argument("Please enter upto 18,446,744,073,709,551,615");
	}
        string mixed;
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
                        cout << endl;
                        system("echo \"\e[92;5;12mPlease enter the length of the password you need\n[Max 18,446,744,073,709,551,615]\nBut Beware !!, this number could crash your system after a few lakhs\nDEPENDS UPON YOUR SYSTEM \e[0m\n\"");
                        cin >> numberof;
                        string allalpha;
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

string safeenter()
{
        termios previouslyentered;
        tcgetattr(STDIN_FILENO, &previouslyentered);
        termios newlyentered = previouslyentered;
        newlyentered.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newlyentered);

        string pass;
        cin >> pass;
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
        cout << "                Welcome to PhraseNUX\n";
        cout << "         ( A password manager by Tamilanth )  " << endl
                 << endl;
        smallbanner();
        system("echo \"\e[38;5;51m[1] - Change Master Password\e[0m\"");
        system("echo  \"\e[38;5;51m[2] - Clear all Passwords\e[0m\"");
        system("echo  \"\e[38;5;51m[3] - Move Passwords to a location\e[0m\"");
        system("echo  \"\e[38;5;51m[4] - Add your own  Password to the Data (created by you)\e[0m\"");
        system("echo \"\e[38;5;51m[5] - Advanced\e[0m\n\n\n\"");
	string Optionadvanced;
        cin >> Optionadvanced;
	Optionadvanced == "1" ? changepass() : Optionadvanced == "4" ? addpassmanually() :Optionadvanced == "2" ? clearallpass() : advancedoptions();
}
void selectservice()
{       cout << endl;
	system("echo  \"\e[38;5;51m[1] - Generate Manually \e[0m\"");

system("echo \"\e[92;5;12mSocial Networks\e[0m\n\"");
cout << "[1] - Instagram";
cout << "[2] - Facebook";
cout << "[3] - Twiitter";
cout << "[4] - Reddit";
cout << "[5] - Telegram";
cout << "[6] - Koo";
cout << "[7] - Cybernity";
cout << "[8] - Houdo";
cout << "[9] - 
system("echo \"\e[92;5;12mProductivity\e[0m\n\"");
cout << "[10] - Sololearn";
cout << "[11] - Canva";
cout << "[12] - Adobe";
cout << "[13] - Enki (Learn to code)";
cout << "[14] - Mimo (Learn python and web dev)";
cout << "[15] - GitHub";
cout << "[16] - Gitlab";
cout << "

system("echo \"\e[92;5;12mMail & others\e[0m\n\"");
cout << "[] - Protonmail";
cout << "[] - Protonmail Mailbox";
cout << "[] - Tutanota";
cout << "[] - Google";
cout << "[] - Yahoo";
cout << "[] - jjsj";




        system("echo  \"\e[38;5;51m[4] - Spotify \e[0m\"");
        system("echo  \"\e[38;5;51m[6] - Apple ID \e[0m\"");
        system("echo  \"\e[38;5;51m[7] - Signal PIN \e[0m\"");
        system("echo  \"\e[38;5;51m[8] - Github \e[0m\"");
	system("echo  \"\e[38;5;51m[9] - Proton (mail/VPN) \e[0m\"");
        system("echo  \"\e[38;5;51m[11] - Protonmail Box \e[0m\"");
        system("echo  \"\e[38;5;51m[14] - Tutanota \e[0m\n\"");
    system("echo  \"\e[38;5;51m[2] - Yahoo \e[0m\"");
        system("echo  \"\e[38;5;51m[3] - Brair messenger \e[0m\"");
        system("echo  \"\e[38;5;51m[4] - Element Messenger \e[0m\"");
        system("echo  \"\e[38;5;51m[5] - Session Messenger \e[0m\"");
    system("echo  \"\e[38;5;51m[7] - PicsArt \e[0m\"");
        system("echo  \"\e[38;5;51m[9] - Wynk Music \e[0m\"");
        system("echo  \"\e[38;5;51m[10] - Gaana (Music \e[0m\"");
        system("echo  \"\e[38;5;51m[11] - JioSaavn \e[0m\"");
        system("echo  \"\e[38;5;51m[12] - Deezer \e[0m\"");
        system("echo  \"\e[38;5;51m[13] - Pandora \e[0m\"");
        system("echo  \"\e[38;5;51m[14] - Tutanota \e[0m\n\"");



}
void changepass()
{
		system("echo \"\e[38;5;9m\n\nWarning !!: Keep this password very strong and please remember this, IF YOU FORGOT THIS PASSWORD, YOU CAN'T RECOVER ANY OF YOUR PASSWORDS\e[0m\n\"");
		system("echo \"\e[92;5;12m Guide for Password creation\e[0m\n\"");
		system("echo \"\e[38;5;9m•PLEASE DONOT INCLUDE ANY SPACES IN  YOUR PASSWORD AND DONOT INCLUDE ANY SYMBOLS OTHER THAN @•_., OF YOU INCLUDE THEN YOU WILL FACE SOMETROUBLE\e[0m\n\"");
		system("echo \"\e[38;5;9m•You can use any ASCII (except  symbols) and DO NOT include Personal information and short passwords are PROHIBITED\e[0m\n\n\n\"");
		system("echo \"\e[38;5;9m\n\nPlease Enter your current password to proceed\e[0m\n\"");
		string oldpass = safeenter();
		system("echo \"\e[\n\nPlease enter your new password\e[0m\n\"");
		string newpass = safeenter();
		if (oldpass == newpass){
		system("echo \"\e[38;5;9m\n\nError:!: The new and old Passwords are same !!\e[0m\n\"");
		this_thread::sleep_for(chrono::milliseconds(1000));
		changepass();
		}
		else {
			string enteringtosys = "aescrypt -d -p " + oldpass + " test.aes";
        		const char *Enteredtosys = enteringtosys.c_str();
        		system(Enteredtosys);
			string enteringtosyse = "aescrypt -e -p " + newpass + " test";
        		const char *Enteredtosyse = enteringtosyse.c_str();
       			system(Enteredtosyse);
			system("echo \"\e[92;5;12mSucess!  Password Changed, returning to Home \e[0m\n\"");
			this_thread::sleep_for(chrono::milliseconds(1000));
               		startup();
			}
}
void addpassmanually()
{
		system("echo \"\e[38;5;9m\n\nNote: Please donot enter your own passwords with spaces (The words after space will NOT be saves!\e[0m\n\"");
		system("echo \"\e[92;5;12mPlease enter your own passsword\e[0m\n\"");
		string ownpass;
		cin >> ownpass;
		system("echo \"\e[38;5;51m\nEnter Your Password:\e[0m\"");
        	string passwd = safeenter();
        	string tag;
        	system("echo \"\e[38;5;51m\nPlease enter the name for this password, so you can identify the passwords with names when you decrypt your passwords\e[0m\"");
        	cin >> tag;
        	cout << "\n";
        	veripassford(passwd);
        	ofstream file;
        	file.open("test", ios_base::app);
        	string writinginput = ownpass + "-" + tag;
        	file << endl <<  writinginput <<  endl;
        	file.close();
        	veripassfore(passwd);
        	passwd = "izsywiabhaishsiwywoanshs";
        	secdel();
}
void clearallpass()
{
		system("aescrypt -d test.aes");
		ifstream fortest;
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
			this_thread::sleep_for(chrono::milliseconds(1000));
			startup();
   		}
}
