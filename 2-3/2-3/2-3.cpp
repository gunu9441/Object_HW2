#include <iostream>
using namespace std;

void biggerisGreater(char* input, char* output)//Lexicographical order function.
{

	int input_count = strlen(input);//Input_count = size of input
	for (int a = input_count - 1; a > 0; a--)
	{
		for (int b = 1; b <= a; b++)
		{
			if (input[a] > input[a - b])
			{
				swap(input[a], input[a - b]);//Swap
				if (input_count - 1 - (a - b) >= 2)
				{
					for (int c = a - b + 1; c < input_count - 1; c++)
					{
						for (int d = c + 1; d <= input_count - 1; d++)
						{
							if (input[c] < input[d])
								continue;
							else
								swap(input[c], input[d]);
						}
					}
				}
				a = 0;//Helping th escaping big loop.
				strcpy(output, input);//Input the input context in output.
				break;//Escape the loop.
			}
		}
	}
}

int main()
{
	int count = 0;
	char input[100];
	char output[100]="no answer";
	cout << "Sample Input1" << endl;
	while (1)
	{
		cout << "Input the string: ";
		cin >> input;//Input the context.
		while (input[count] != '\0')//Exception handling-string length.
		{
			count++;
		}
		if (count > 10)
		{
			cout << "Please input another correct string." << endl;
			count = 0;
			continue;
		}
		break;
	}
	cout << endl;
	biggerisGreater(input, output);//Implementation of fucntion.
	cout << "Sample output" << endl << output << endl;

	return 0;//End.
}