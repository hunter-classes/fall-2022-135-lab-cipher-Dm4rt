#include <iostream>
#include <vector>
#include "caesar.h"

char shiftChar(char c, int rshift){
  if(c>=65&&c<=90){
    if(c+rshift>90){
      int temp=(c+rshift)-90;
      while(temp>26){
	temp=temp%26;
      }
      c=64+temp;
    }
    else{
      c=c+rshift;
    }
    
    return c;
  }
  else if(c>=97&&c<=122){
    if(c+rshift>122){
      int temp=(c+rshift)-122;
      while(temp>26){
	temp=temp%26;
      }
      c=96+temp;
    }
    else{
      c=c+rshift;
    }
    return c;
  }
  else{
    return c;
  }
}

std::string encryptCaesar(std::string plaintext, int rshift){
  std::string encrypted;
  for(int x=0;x<plaintext.length();x++){
    encrypted+=(int)shiftChar(plaintext[x],rshift);
  }
  return encrypted;
}

std::string solve(std::string encrypted_string){
  std::vector<int> freq[26];
  return "";
}
