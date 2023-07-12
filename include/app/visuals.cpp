#pragma once

//Banners
void smallbanner()
{
  std::cout << "\033[1;36m                 ▁▂▄▅▆▇█ ƬΛ █▇▆▅▄▂▁         \033[0m\n\n";
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
  std::cout << "\033[1;36m\n\n";
  std::cout << "\033[1;36m                  |''||''|     |\n";
  std::cout << "\033[1;36m                     ||       |||\n";
  std::cout << "\033[1;36m                     ||      |  ||\n";
  std::cout << "\033[1;36m                     ||     .''''|.\n";
  std::cout << "\033[1;36m                    .||.   .|.  .||.\033[0m\n\n\n\n";
}

void banner3()
{
  std::cout << "\033[1;36m\n\n";
  std::cout << "\033[1;36m                     ╭━━━━┳━━━╮    \n";
  std::cout << "\033[1;36m                     ┃╭╮╭╮┃╭━╮┃    \n";
  std::cout << "\033[1;36m                     ╰╯┃┃╰┫┃╱┃┃    \n";
  std::cout << "\033[1;36m                     ╱╱┃┃╱┃╰━╯┃    \n";
  std::cout << "\033[1;36m                     ╱╱┃┃╱┃╭━╮┃    \n";
  std::cout << "\033[1;36m                     ╱╱╰╯╱╰╯╱╰╯    \033[0m\n\n\n\n";
}

void banner4()
{
  std::cout << "\033[1;36m\n\n";
  std::cout << "\033[1;36m                  ▄▄▄█████▓ ▄▄▄      \n";
  std::cout << "\033[1;36m                  ▓  ██▒ ▓▒▒████▄    \n";
  std::cout << "\033[1;36m                  ▒ ▓██░ ▒░▒██  ▀█▄  \n";
  std::cout << "\033[1;36m                  ░ ▓██▓ ░ ░██▄▄▄▄██ \n";
  std::cout << "\033[1;36m                    ▒██▒ ░  ▓█   ▓██▒\n";
  std::cout << "\033[1;36m                    ▒ ░░    ▒▒   ▓▒█░\n";
  std::cout << "\033[1;36m                      ░      ▒   ▒▒ ░\n";
  std::cout << "\033[1;36m                    ░        ░   ▒   \n";
  std::cout << "\033[1;36m                          ░  ░\033[0m\n\n\n\n";
}
void banner5()
{
  std::cout << "\033[1;36m\n\n";
  std::cout << "\033[1;36m                  '||''|.  '||' '|'\n";
  std::cout << "\033[1;36m                   ||   ||   || |   \n";
  std::cout << "\033[1;36m                   ||...|'    ||    \n";
  std::cout << "\033[1;36m                   ||        | ||   \n";
  std::cout << "\033[1;36m                  .||.     .|   ||. \033[0m\n\n\n\n";
}

//Randomly select a banner

void banner()
{
  duthomhas::csprng rng;
  short int ta = (rng() % 5);
  ta == 1 ? banner1() : ta == 2 ? banner2()
    : ta == 3   ? banner3()
    : ta == 4   ? banner4()
    : banner5();
}

//Advanced Options menu

bool advancedoptions()
{
  std::cout << "\033c";
  banner();
  std::cout << "                Welcome to PhraseNuX\n";
  std::cout << "         ( A password manager by Tamilanth )  "
	    << "\n"
	    << "\n";
  smallbanner();
  std::cout << "\033[1;36m\n[1] - Change Master Password\033[0m\n";
  std::cout << "\033[1;36m[2] - Add your own  Password to the Database (created by you)\033[0m\n";
  std::cout << "\033[1;36m[3] - Check for updates\e[0m\n";
  std::cout << "\033[1;36m[4] - Change the phrase to call the program\033[0m\n";
  std::cout << "\033[1;36m[5] - Return to Main Menu\e[0m\n\n\n\n";
  char Optionadvanced;
  std::cout << "Please select your Option 1 or 2 or 3 or 4:\n";
  std::cin >> Optionadvanced;
  if (Optionadvanced == '1')
    {
      if (changepass())
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
  else if (Optionadvanced == '2')
    {
      if (addpassmanually())
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
  else if (Optionadvanced == '4')
    {
      if (changeprogramcaller())
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
  else if (Optionadvanced == '3')
    {
      if (checkforupdates(0))
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
  else if (Optionadvanced == '5')
    {
      return true;
    }
  else
    {
      std::cout << "\033[1;31m\n\nError:!: Please select 1 or 2 or 3 or 4\033[0m\n";
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      std::cout << "\033c";
      advancedoptions();
      return false;
    }
  return true;
}

// Function that displays the custom option banner

void optionsB()
{
  std::cout << "\n";
  std::cout << "\033[1;36m[1] - Numbers Only Mode \033[0m\n";
  std::cout << "\033[1;36m[2] - Alphabets Only Mode \033[0m\n";
  std::cout << "\033[1;36m[3] - Alphabets-Numeric Mode \033[0m\n";
  std::cout << "\033[1;36m[4] - Mixed Mode \033[0m\n";
  std::cout << "\033[1;36m[5] - Main Menu \033[0m\n\n";
}

//Funtion that displays the main menu

void optionsA()
{
  std::cout << "\033c";
  banner();
  std::cout << "                Welcome to PhraseNuX\n";
  std::cout << "         ( A password manager by Tamilanth )  "
	    << "\n"
	    << "\n";
  smallbanner();
  std::cout << "\033[1;36m[1] - Show Saved Passwords\033[0m\n";
  std::cout << "\033[1;36m[2] - Create a  New Password\033[0m\n";
  std::cout << "\033[1;36m[3] - Delete a Password\033[0m\n";
  std::cout << "\033[1;36m[4] - Exit\033[0m\n";
  std::cout << "\033[1;36m[5] - Advanced\033[0m\n\n\n";
}
