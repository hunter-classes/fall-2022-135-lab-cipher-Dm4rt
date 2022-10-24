#include <iostream>
#include <cmath>
#include "decryption.h"
#include "caesar.h"
#include "vigenere.h"

std::string decryptCaesar(std::string ciphertext, int rshift){
  return encryptCaesar(ciphertext,26-rshift);
}

std::string decryptVigenere(std::string ciphertext,std::string keyword){
  std::string newKey;
  for(int x=0;x<keyword.length();x++){
    int newInt=keyword[x]-97;
    char newChar=26-newInt;
    newChar=newChar+97;
    newKey+=(int)newChar;
  }
  
  
  return encryptVigenere(ciphertext,newKey);
}
