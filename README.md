

            |''||''|     |   
               ||       |||    
               ||      |  ||    
               ||     .''''|.   
              .||.   .|.  .||.  


          Hey, Welcome to PhraseNUX 


# How To Install

Note: PhraseNUX was created with a average user in mine, who doesn't have too much of tech knowledge. so, For security reasons the source codes of the application will be deleted after installation by default, If you are an advanced user and like to play with the codes, please edit the **install/start** file which is written in bash and edit the hashing function in the **install/PhraseNUX.cpp**

- Open a Terminal

- Install the package **`git`**

- Clone this repository by running
    
    **`git clone https://github.com/Tamilanth/PhraseNUX/`** 

- Open the **PhraseNUX** directory in Terminal by typing

     **`cd PhraseNUX`**

- Open the install directory in the terminal by typing

     **`cd install`**

- Compile the **install_dependencies.cpp** file by typing in your terminal

     **`g++ install_dependencies.cpp -o install ../AES/aes.c ../AES/sha256.c ../AES/password.c -I.`**


**Note: Please make sure you have a stable internet connection before the next step it will take around 2 seconds and takes about 1 - 3 MB of Data and space**

- Run the compiled binary file 

     **`./install`**

- Now close the terminal and open the **`PhaseNUX`** directory

### That's all installing

Now it will ask for a master Password 

***(Note: This password will be used for decrypting and encrypting your password, you can change this anytime inside the program, _only if you have your current password_, if you forgot your password _You can't recover any of your passwords***

***• Keep your passwords very long (atleast 50 chars)  and _Donot_ include any personal/guessable words to your password***

# One tap installation
Alternatively if you need to install the program in a single tap

**`git clone https://github.com/Tamilanth/PhraseNUX/ && cd PhraseNUX && cd install && g++ install_dependencies.cpp ../AES/aes.c ../AES/sha256.c ../AES/password.c -I. && ./install`**

# How to Run

Just type the name which you entered during the installation process

# FAQs

- How to change the password ?

Open the program in your terminal


![Model](/images/reference1.jpg)

- Enter the option _5_ for advanced options to be opened

![Model](/images/reference2.jpg)

- Enter the option _1_ to change the password
