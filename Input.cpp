#include"Input.h"
#include <iostream>

using namespace std;

template<typename Generic>
inline Generic check(Generic inputVariable, Generic limitationInput)
{
	static LetsCheck* J;
	int good;
	do
	{
		good = 1;
		inputVariable = J->Check(inputVariable, limitationInput, good);
	} while (limitationInput == inputVariable && good == 0);
	return inputVariable;
}

Input::Input(void) {}

int Input::Int(void)
{
	static int x, y;
	return check(x, y);
}

float Input::Float(void)
{
	static float x, y;
	return check(x, y);
}

char Input::Char(void)
{
	static char x, y;
	return check(x, y);
}

bool Input::Bool(void)
{
	static bool x, y;
	return check(x, y);
}

Input::~Input(void) {}
