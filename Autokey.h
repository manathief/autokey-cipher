#pragma once
#include <iostream>
#include <string>
#include <vector>

class Autokey
{
private:
	//class variables
	std::string cKey;
	std::string plaintext;
	std::string ciphertext;
	std::vector<std::string> tableau;

	//internal functions
	void parseInput(std::string& input);
	void buildTableau();
	char lookupEncrypt(char x, char y);
	char lookupDecrypt(char c, char k);
public:
	//constructors
	Autokey();
	Autokey(std::string key);

	//mutators
	void setKey(std::string key);

	//accessors
	std::string getKey();

	//member functions
	void encipher(std::string ptext);
	void decipher(std::string ctext);
};
