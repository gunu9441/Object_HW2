#include "Decode.h"
#include "Encode.h"
#include <iostream>
using namespace std;

int main()
{
	Encode encode;
	encode.inputWord();
	encode.encodeWord();
	encode.printEncResult();
	cout << endl;
	Decode decode;
	decode.setBuf(encode.getBuf());
	decode.decodebin();
	decode.printWord();
	return 0;
}