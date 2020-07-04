#include "Decode.h"



Decode::Decode()
{
}


Decode::~Decode()
{
}

void Decode::setBuf(char * buf)//Save the encoding thing.
{
	int count = 0;
	while (buf[count] == '0' || buf[count] == '1')
	{
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		buffer[i] = buf[i];//Moving.
	}
}

void Decode::printWord()
{
	int count = 0;
	cout << "Decoding result" << endl;
	while (word[count]>='a' && word[count]<='z' )
	{
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		cout << word[i];
	}
	cout << endl;
}

int Decode::decodebin(void)
{
	int zero_count = 0;
	int total_count = 0;
	int word_count = 0;

	while(buffer[total_count] == '0' || buffer[total_count] == '1')
	{
		if (buffer[total_count] == '0' || buffer[total_count] == '1')
		{
			while (buffer[total_count] == '0')
			{
				zero_count++;
				total_count++;
				if (zero_count == 25)//Exception handling - 'z'
					break;
			}
			if (zero_count == 25)//Exception handling - 'z'
			{
				word[word_count] = (zero_count + 97);
			}
			else
			{
				word[word_count] = (zero_count + 97);
				total_count++;
			}
			zero_count = 0;
			word_count++;
		}
	}
	return 0;
}
