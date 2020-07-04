#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void loadTxt(ifstream& inFile, string& strFile, int& nCaesar)
{
	int total_cnt=0;
	int move_cnt=0;//Count the number of moving part
	int print_cnt = 0;

	if (!inFile.is_open())return;

	int fileSize = 0;

	inFile.seekg(0, ios::end);
	fileSize = inFile.tellg();
	inFile.seekg(0, ios::beg);

	strFile.resize(fileSize);
	inFile.read(&strFile[0], fileSize);

	while (strFile[total_cnt] != '\0')
	{
		if (strFile[total_cnt] == '\n')
		{
			move_cnt = total_cnt;
			while (strFile[move_cnt + 1] != '\0')
			{
				strFile[move_cnt] = strFile[move_cnt + 1];
				move_cnt++;
			}
			strFile[move_cnt] = strFile[move_cnt + 1];
		}
		total_cnt++;
	}

	while(strFile[print_cnt] != '\0')
	{
		strFile[print_cnt] += nCaesar;
		print_cnt++;
	}

	/*
	for (a = 0; a < fileSize; a++)
	{
		strFile[a] += nCaesar;
	}
	*/

}

void writeTxt(ofstream& outFile, string& strFile)
{
	if (!outFile.is_open())return;

	for (char ch : strFile)
	{
		outFile << ch;
	}
}

int main()
{
	int nCaesar;
	string strFileName = "Diary_15yearsOld";
	string strFileFormat = ".txt";
	string strFile;

	ifstream inFile(strFileName + strFileFormat);
	ofstream outFile(strFileName + "_encryption" + strFileFormat);

	if (!inFile.is_open() || !outFile.is_open())
	{
		cout << "file is not opened" << endl;
	}

	cout << "Sample Input" << endl;
	while (1)
	{
		cout << "Input the shift number: ";
		cin >> nCaesar;

		if (0 <= nCaesar && 26 >= nCaesar)
			break;
		else
		{
			cout << "Please input correct number!" << endl;
			continue;
		}
	}

	cout << endl << endl << endl << endl;
	cout << "Sample output (it need to be written in a new file\"" << strFileName + "_encryption" + strFileFormat << "\") " << endl;
	cout << endl << endl;

	loadTxt(inFile, strFile, nCaesar);

	cout << strFile << endl;

	writeTxt(outFile, strFile);

	inFile.close();
	outFile.close();

	return 0;
}


/* another source - loadText function
for (a = 0; a < fileSize; a++)
{
if (strFile[a] == '\n')
{
for (b = a; b < fileSize; b++)
{
strFile[b] = strFile[b + 1];
}
}
}


for(a = 0; a < fileSize; a++)
{
strFile[a] += nCaesar;
}
*/