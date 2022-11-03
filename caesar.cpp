#include <iostream>
#include <vector>
#include <cmath>
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
  const std::string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::vector<double> freq;

  const std::vector<double> engFreq={8.12,1.49,2.71,4.32,12.02,2.30,2.03,5.92,
			       7.31,0.10,0.69,3.98,2.61,6.95,7.68,1.82,0.11,
			       6.02,6.28,9.10,2.88,1.11,2.09,0.17,2.11,0.07};

  int lowestDistance=-1;
  int lowDistShift;
  for(int shift=1;shift<26;shift++){
    std::string newMessage=encryptCaesar(encrypted_string,shift);
    std::vector<double> newFreq (0,0);
    freq.swap(newFreq);
    for(int x=0;x<26;x++){
      char curLetter=alpha[x];
      int letterCount=0;
      for(int j=0;j<newMessage.length();j++){
	if(toupper(newMessage[j])==curLetter){
	  letterCount++;
	}
      }
      double letterFreq=(letterCount/(newMessage.length()*1.00))*100;
      freq.push_back(letterFreq);
      
    }
    int sum=0;
    for(int c=0;c<26;c++){
      double sub=abs(engFreq.at(c)-freq.at(c));
      sum+=pow(sub,2);
    }
    int curDistance=0;
    curDistance=sqrt(sum);
    if(lowestDistance==-1){
      lowestDistance=curDistance;
      lowDistShift=shift;
    }
    else if(curDistance<lowestDistance){
      lowestDistance=curDistance;
      lowDistShift=shift;
      
    }
    
  }
  return encryptCaesar(encrypted_string,lowDistShift);
}
