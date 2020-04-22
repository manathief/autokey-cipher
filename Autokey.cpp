#include "Autokey.h"

Autokey::Autokey(std::string key)
{
	this->cKey = key;
	parseInput(cKey);
	std::cout << "Key: " << cKey << "\n\n";
}
Autokey::Autokey()
{
	cKey = "";
	ciphertext = "";
	plaintext = "";
}

void Autokey::setKey(std::string key) 
{
	this->cKey = key;
	parseInput(cKey);
}

std::string Autokey::getKey() 
{ 
	return cKey; 
}

void Autokey::encipher(std::string ptext)
{
	if (tableau.empty()) 
		buildTableau();

	this->ciphertext.clear();
	this->plaintext = ptext;
	parseInput(plaintext);

	unsigned int len = plaintext.length();
	std::string keyText = cKey + plaintext;
	keyText.resize(len);
	
	for (unsigned int i = 0; i < len; ++i)
	{
		char x = plaintext.at(i);
		char y = keyText.at(i);

		char enc = lookupEncrypt(x, y);

		ciphertext += enc;
	}
	keyText.clear();	// comment out to see generated keyText
	/*
	std::cout << "Input plaintext:\t" << plaintext << "\n";
	std::cout << "Generated keytext:\t" << keyText << "\n";
	//*/
	std::cout <<"Output ciphertext:\t"<< ciphertext << "\n\n";
}

void Autokey::decipher(std::string ctext)
{
	if (tableau.empty()) 
		buildTableau();

	this->plaintext.clear();
	this->ciphertext = ctext;
	parseInput(ciphertext);

	unsigned int len = ciphertext.length();
	std::string keyText = cKey;
	keyText.resize(len);
	
	for (unsigned int i = 0; i < len; ++i)
	{
		char c = ciphertext.at(i);
		char k = keyText.at(i);
		
		char dec = lookupDecrypt(c,k);

		if (keyText.length() < len) 
			keyText += dec;
		plaintext += dec;
	}
	keyText.clear();	// comment out to see generated keyText
	/*
	std::cout << "Input ciphertext:\t" << ciphertext << "\n";
	std::cout << "Generated keytext:\t" << keyText << "\n";
	//*/
	std::cout << "Output plaintext:\t" << plaintext << "\n\n";
}

char Autokey::lookupEncrypt(char x, char y)
{
	int row = y - 'A';
	int col = x - 'A';

	return tableau[row][col];
}

char Autokey::lookupDecrypt(char c, char k)
{
	int row = k - 'A';

	for (int i = 0; i < 26; ++i)
	{
		if (tableau[row][i] == c)
			return i + 'A';
	}
	return '-';

}

void Autokey::buildTableau()
{
	std::string row;
	int offset = 0;

	while (offset < 26) 
	{
		char ch = 'A' + offset;
		for (int i = 0; i < 26; ++i)
		{
			if (ch > 'Z') 
				ch = 'A';
			row += ch;
			ch++;
		}
		tableau.push_back(row);
		row.clear();
		offset++;
	}
	//for (auto x:tableau) std::cout << x << "\n";		// print tableau check
}

void Autokey::parseInput(std::string& input)
{
	for (auto it = input.begin(); it != input.end(); ++it)
	{
		if (isspace(*it))
			input.erase(it--);
		if (isalpha(*it))
			*it = toupper(*it);
	}
	//std::cout << in;		// parsed string check
}
