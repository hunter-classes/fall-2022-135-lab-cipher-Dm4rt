#include <iostream>
#include <cmath>
#include "vigenere.h"
#include "caesar.h"

std::string encryptVigenere(std::string plaintext, std::string keyword){
  std::string encrypted;
  int index=0;
  for(int x=0;x<plaintext.length();x++){
    int shift=keyword[index]-97;
    encrypted+=shiftChar(plaintext[x],shift);
    if((plaintext[x]>=65&&plaintext[x]<=90)||(plaintext[x]>=97&&plaintext[x]<=122)){
      index++;
    }
    if(index==keyword.length()){
      index=0;
    }
  }
  return encrypted;
}
