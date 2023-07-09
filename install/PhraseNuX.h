#ifndef LIBS

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


//Declaring all functions and checkers and variables in global scope
bool aescrypt(char type, const char **pas);
bool checkforupdates(bool start);
bool addpassmanually();
bool changeprogramcaller();
bool changepass();
std::string tagforsearch;
std::string startsha = "0552d3158a2bcfda0f577c5f0fe2fb624ba17d5660dd8bafd9c5dd3e871889c1";
bool safeenterstop();
bool selectservice();
bool advancedoptions();
std::string safeenter();
bool showpass(bool what, std::string &passthen);
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



#endif
