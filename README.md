

            |''||''|     |   
               ||       |||    
               ||      |  ||    
               ||     .''''|.   
              .||.   .|.  .||.  


          Hey, Welcome to PhraseNUX 
 



# Intro

- PhraseNUX is a command-line password manager and a command-line  password generator specially made for Linux

- PhraseNUX is a powerfull as well as secure command-line application

- PhraseNUX depends on AES encryption algorithm (an Open-sourced and powerfull encryption algorithm) for encrypting your passwords 

- PhraseNUX uses a Cryptographically secure Random charecter generator



# How to install

Note: PhraseNUX was created with a average user in mine, who doesn't have too much of tech knowledge. so, For security reasons the source codes of the application will be deleted after installation by default, If you are an advanced user and like to play with the codes, please edit the **install/start** file which is written in bash and edit the hashing function in the **install/PhraseNUX.cpp**



- Open the install directory

     **`cd install`**

- Compile the **install_dependencies.cpp** file

     **`g++ install_dependencies.cpp -o install`**


**Note: Please make sure you have a stable internet connection before the next step it will take around 2 seconds and takes about 1 - 10 MB of Data and space**

- Run the compiled binary file 

     **`./install`**



### That's all installing

Now it will ask for a master Password 

***(Note: This password will be used for decrypting and encrypting your password, you can change this anytime inside the program, _only if you have your current password_, if you forgot your password _You can't recover any of your passwords***

***• Donot include any spaces or symbols in your password _this may cause you troubles_***

***• Keep your passwords very long (atleast 50 chars)  and _Donot_ include any personal/guessable words to your password***

# How to Run

For now you need to run

`**./PhraseNUX**`

In the ***same directory***

In future It will be modified like you can run anywhere
