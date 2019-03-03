#include "Check.h"
#include<iostream>

using namespace std;

LetsCheck::LetsCheck() {}

int LetsCheck::Check(int i, int a, int& g)
{
	try
	{
		float k;
		cin >> k;     //input stored in 'k'
		i = (int)k;		 //input copied to 'i' (type cast to int)
		if (!cin || i != k) throw 1;
		/*(!cin) will return 0 when cin is carried out successfully i.e. no char is inputted.
		BUT if decimal input is given, (!cin) will still return 0. Thus, i!=k checks for 'k'
		(input) to be an integer and not a decimal value.*/
		else if (cin.get() == '\n') throw 'a';
		/*if 'k' is inputted as
		1. 34 (an integer)
		2. 34.5 (a float) ~ already negated
		cin.get() == '\n' returns 1
		else if 'k' is inputted as
		1. 34...
		2. 34&%>#@DFW
		3. 34.4t     (etc)
		cin.get() == '\n' returns 0
		thus, this condition is true for a correct input.*/
		else throw (cin.get());
		/*Since for an integer following other characters, cin.get() != '\n', thus for such
		a wrong input, throw cin.get() which is in actual returing 0 here. (0 is an int)*/
	}
	catch (int)		//catch or follow up the code when an int is thrown
	{
		block();
		g = 0;
		return a;
		/*input 'i' is made equal to check variable 'a' to allow while loop to continue and
		thus allow user to re-enter input. (refer to Input.cpp template function)*/
	}
	catch (char)	//catch or follow up the code when a char is thrown
	{
		return i;
		/*Correct input entered is returned. Do note that g is not switched to 0 and thus
		the while loop breaks even if i==a is true.*/
	}
}

float LetsCheck::Check(float f, float b, int& g)
{
	try
	{
		cin >> f;
		if (!cin) throw 1;	 // if char
		else if (cin.get() == '\n') throw 'a';		//else if not char (float is followed by '\n')
		else throw (cin.get());		//else (if float is followed by string, e.g. 3.14tr&7)
	}
	catch (int)
	{
		block();
		g = 0;
		return b;
	}
	catch (char)
	{
		return f;
	}
}

char LetsCheck::Check(char ch, char c, int& g)
{
	cin >> ch;
	try
	{
		if (cin.get() == '\n') throw 'a';	//if single char
		else if (cin.get()) throw 1;	//else (if char is followed by string, e.g. augdyhg)
	}
	catch (int)
	{
		block();
		g = 0;
		return c;
	}
	catch (char)
	{
		return ch;
	}
}

bool LetsCheck::Check(bool b, bool d, int& g)
{
	int temp;
	cin >> temp;    //input stored in temp
	if (temp == true)
	{
		return temp;
		/*if input is 1, return input. This way b equals
		1 and it is no longer equal to d and thus the
		while loop breaks (refer to the function
		bool check(bool, int) in Input.cpp)*/
	}
	if (temp != true)
	{
		if (temp == false)
		{
			return temp;
			/*if input is 0, return input. Note that b is
			still equal to d. Thus, donot put g to 0
			(g==1 -> TRUE) so that the while loop breaks
			(refer to the function
			bool check(bool, int) in Input.cpp)*/
		}
		block();
		g = 0;
		return d;
	}
}

void LetsCheck::block(void)		//common block of code to all funtions in class LetsCheck
{
	cout << "\n Something went wrong.\n";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail(), '\n');
	//ignore the available number of characters in the read buffer until newline character
	cout << " Re-enter response: ";
}

LetsCheck::~LetsCheck() {}
