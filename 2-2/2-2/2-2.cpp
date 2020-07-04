#include <iostream>

using namespace std;

void militaryTimeAdd(int* pHour, int* pMin, int* pSec, int addHour, int addMin, int addSec)//Calculating the time function.
{
	*pHour += addHour;//addition
	*pMin += addMin;
	*pSec += addSec;

	while (1)//loop
	{
		if (*pSec >= 60)//If seconds are more than 60, it turns to 0 and program operate the adding 1 to minute.
		{
			*pSec -= 60;
			*pMin += 1;
			if (*pSec == 1)
				*pSec = 0;
		}

		if (*pMin >= 60)//If minutes are more that 60, it turns to 0 and program operate the adding 1 to hour.
		{
			*pMin -= 60;
			*pHour += 1;
			if (*pMin == 1)
				*pMin = 0;
		}	

		if (*pHour >= 24)//If hours are more that 24, it turns to 0.
			*pHour -= 24;

		if (*pMin < 60 && *pSec < 60 && *pHour < 24)//Finish the changing.
			break;
	}
}


int main()
{
	int input_h, input_m, input_s;
	int add_h, add_m, add_s;

	cout << "Sample Input0" << endl;
	cout << "input time" << endl;
	while (1)
	{
		cout << "h: ";
		cin >> input_h;
		if (0 > input_h || input_h > 23)//Exception handling.
		{
			cout << "Please input another number. It is out of range." << endl;
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "m: ";
		cin >> input_m;
		if (0 > input_m || input_m > 59)//Exception handling.
		{
			cout << "Please input another number. It is out of range." << endl;
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "s: ";
		cin >> input_s;
		if (0 > input_s || input_s > 59)//Exception handling.
		{
			cout << "Please input another number. It is out of range." << endl;
			continue;
		}
		break;
	}

	cout << "add time" << endl;
	while (1)
	{
		cout << "h: ";
		cin >> add_h;
		if (0 > add_h || add_h > 1000000)//Exception handling.
		{
			cout << "Please input another number. It is out of range." << endl;
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "m: ";
		cin >> add_m;
		if (0 > add_m || add_m > 1000000)//Exception handling.
		{
			cout << "Please input another number. It is out of range." << endl;
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "s: ";
		cin >> add_s;
		if (0 > add_s || add_s > 1000000)//Exception handling.
		{
			cout << "Please input another number. It is out of range." << endl;
			continue;
		}
		break;
	}

	cout << "Sample output0" << endl;
	cout << "output time" << endl;

	militaryTimeAdd(&input_h, &input_m, &input_s, add_h, add_m, add_s);//Implementation of function.
	cout << "h: " << input_h << " " << "m: " << input_m << " " << "s: " << input_s << endl;

	return 0;//End.
}
