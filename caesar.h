#pragma once
#include <string>
#include <vector>

char shiftChar(char c, int rshift);
std::string encryptCaesar(std::string plaintext, int rshift);
std::string solve(std::string encrypted_string);
