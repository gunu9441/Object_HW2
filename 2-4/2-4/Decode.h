#pragma once
#include <iostream>
using namespace std;

class Decode
{
private:
	char word[255];//word
	char buffer[255];//binary
public:
	Decode();
	~Decode();

	void setBuf(char*buf);//Save the buffer.
	void printWord();

	int decodebin(void);//decode the endcoding thing.
};

