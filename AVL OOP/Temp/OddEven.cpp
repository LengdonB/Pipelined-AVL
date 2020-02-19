#include "OddEven.h"
#include<iostream>
using namespace std;

OddEven::OddEven()
{
	nextFunction = NULL;
}

void OddEven::setNextFunction(IPipe * nextFunction)
{
	if (this->nextFunction == NULL)
		this->nextFunction = nextFunction;
	else
		this->nextFunction->setNextFunction(nextFunction);
}

int OddEven::start(int value, Node * current)
{
	if (value % 2 == 0)
		cout << value << " is Even.\n";
	else
		cout <<value<< " is Odd\n";

	if (nextFunction != NULL)
		nextFunction->start(value, current);
	return value;
}
