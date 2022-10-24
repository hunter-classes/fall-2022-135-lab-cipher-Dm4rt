#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"

int main()
{
  std::cout<<"encryptCaesar('Way to Go!,5'): "<<encryptCaesar("Way to Go!", 5)<<std::endl;
  std::cout<<"encryptVigenere('Hello, World!', 'cake'): "<<encryptVigenere("Hello, World!", "cake")<<std::endl;
  std::string encrypted=encryptCaesar("Way to Go!",5);
  std::cout<<"decryptCaesar('Bfd yt Lt!', 'cake'): "<<decryptCaesar(encrypted,5)<<std::endl;
  encrypted=encryptVigenere("Hello, World!", "cake");
  std::cout<<"decryptVigenere('Jevpq, Wyvnd!','cake'): "<<decryptVigenere(encrypted,"cake")<<std::endl;
  return 0;
  
}
