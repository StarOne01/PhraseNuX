

            |''||''|     |   
               ||       |||    
               ||      |  ||    
               ||     .''''|.   
              .||.   .|.  .||.  


          Hey, Welcome to PhraseNuX 


# How To Install

Note: PhraseNuX was created with a average user in mine, who doesn't have too much of tech knowledge. so, For security reasons the source codes of the application will be deleted after installation by default, If you are an advanced user and like to play with the codes, please edit the **install/start** file which is written in bash and edit the hashing function in the **install/PhraseNuX.cpp**

- Open a Terminal

- Install the package **`git`**

- Clone this repository by running
    
    **`git clone https://github.com/Tamilanth/PhraseNuX/`** 

- Open the **PhraseNuX** directory in Terminal by typing

     **`cd PhraseNuX`**

- Open the install directory in the terminal by typing

     **`cd install`**

- Compile the **install_dependencies.cpp** file by typing in your terminal

     **`g++ install_dependencies.cpp ../hash/sha3.cpp ../AES/aes.c ../AES/sha256.c ../AES/password.c -I. -o install && ./install`**


**Note: Please make sure you have a stable internet connection before the next step it will take around 2 seconds and takes about 1 - 3 MB of Data and space**

- Run the compiled binary file 

     **`./install`**

- Now close the terminal and open the **`PhaseNUX`** directory

### That's all installing

Now it will ask for a master Password 

***(Note: This password will be used for decrypting and encrypting your password, you can change this anytime inside the program, _only if you have your current password_, if you forgot your password _You can't recover any of your passwords_***

***• Keep your master password very long (atleast 20 chars)  and _Donot_ include any personal/guessable words to your password***

# One tap installation

Alternatively if you need to install the program in a single tap

**`sudo apt install git && git clone https://github.com/Tamilanth/PhraseNuX/ && cd PhraseNuX && cd install && g++ install_dependencies.cpp -lcurl ../AES/aes.c ../AES/sha256.c ../AES/password.c -I. -o install && ./install`**

# How to Run

Just type the keyword which you entered during the installation process

# FAQs

### How to change the master password ?

Open the program in your terminal

![Model](/images/reference1.jpg)

- Enter the option _5_ for advanced options to be opened

- Enter the option _1_ to change the password and enter your old master password and new master password now

### How can i backup my passwords ?

- By default the passwords will never leave your phone, so if you need to store your passwords somewhere safely, you are free to copy it.
The Encrypted passwords are stored in the filename `"Encrypted_Passwords.aes"` in PhraseNuX Folder

***(Note: Do this only if you trust the place you store the passwords and your master password should be atleast 20 chars to ensure the safety of your encrypted passwords)***
