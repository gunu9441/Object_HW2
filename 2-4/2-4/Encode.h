#pragma once
#include <iostream>
using namespace std;

class Encode
{
private:
	char word[255];
	char buffer[255];
public:
	Encode();
	~Encode();

	void inputWord();
	char* getBuf(void);
	void printEncResult();

	int encodeWord();
};

