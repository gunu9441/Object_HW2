#include "Encode.h"



Encode::Encode()
{
}


Encode::~Encode()
{
}

void Encode::inputWord()
{
	cout << "Input word: ";
	cin >> word;
	cout << endl;
}

char * Encode::getBuf(void)
{
	return buffer;
}

void Encode::printEncResult()
{
	int count = 0;
	cout << "Encoding result" << endl;
	while (buffer[count] == '0'|| buffer[count] == '1')
	{
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		cout << buffer[i];
	}
	cout << endl;
}

int Encode::encodeWord()
{
	int count = 0;
	int num_buffer=0;
	while (word[count] != 0)//Count the valuable 'count'.
	{
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		int num = word[i] - 97;//the number of word's letter.
		
		for (num; num > 0; num--)
		{
			buffer[num_buffer] = '0';
			num_buffer++;
		}
		if (word[i] == 'z')//Exception handling -'z'
			buffer[num_buffer] = '0';
		else 
		{
			buffer[num_buffer] = '1';
			num_buffer++;
		}
	}
	return 0;
}
