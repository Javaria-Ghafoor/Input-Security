#include "Input.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void redirect(void);

void main()
{
	Input J;
	int i;
	float f;
	char c;
	bool b;
	char* s;
	cout << " Try to crash my program :P" << endl
		 << endl;
	cout << " MENU:" << endl
		 << " 1. Input an integer" << endl
		 << " 2. Input a floating number" << endl
		 << " 3. Input a character" << endl
		 << " 4. Input a boolean value" << endl
		 << endl;
	cout << " Enter Response: ";
	switch (J.Int())
	{
	case 1:
		cout << endl
			 << " Enter an integer: ";
		i = J.Int();
		cout << " Your integer is: " << i << endl;
		break;
	case 2:
		cout << endl
			 << " Enter a floating number: ";
		f = J.Float();
		cout << " Your floating number is: " << f << endl;
		break;
	case 3:
		cout << endl
			 << " Enter an character: ";
		c = J.Char();
		cout << " Your character is: " << c << endl;
		break;
	case 4:
		cout << endl
			 << " Enter a boolean value: ";
		b = J.Bool();
		cout << " Your boolean value is: " << b << endl;
		break;
	default:
		cout << endl
			 << " Kindly enter an integral number in range:" << endl
			 << "			1<=Response<=4	:)" << endl;
		redirect();
	}
	cout << endl
		 << " Do you want to try a different input? (Y/N)" << endl
		 << " Response: ";
	switch (J.Char())
	{
	case 'y':
	case 'Y':
		redirect();
		break;
	case 'n':
	case 'N':
		cout << endl
			 << " Press any key to close the program..";
		_getch();
		exit(1);
		break;
	default:
		cout << endl
			 << " We could not interpret your response :P" << endl;
		redirect();
	}
}

void redirect (void)
{
	cout << endl 
		 << " Press any key to be redirected to MENU..";
	_getch();
	system("cls");
	main();
}
