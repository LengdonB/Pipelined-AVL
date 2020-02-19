#include "CoPrime.h"
#include <iostream>
using namespace std;

CoPrime::CoPrime()
{
	nextFunction = NULL;
}

void CoPrime::setNextFunction(IPipe * nextFunction)
{
	if (this->nextFunction == NULL)
		this->nextFunction = nextFunction;
	else
		this->nextFunction->setNextFunction(nextFunction);
}

int CoPrime::start(int value, Node * current)
{
	if (current != NULL)
	{
		int gcd = 0;//greatest common divisor
		for (int i = 1; i <= current->key && i <= value; i++)//checks if there is a common factor
		{
			if (current->key % i == 0 && value % i == 0)
			{
				gcd = i;
			}
		}
		if (gcd == 1)
			cout << "(" << current->key << ", " << value << ") are Co-Prime." << endl;
		else
			cout << "(" << current->key << ", " << value << ") are not Co-Prime" << endl;
	}

	if (nextFunction != NULL)
		nextFunction->start(value, current);
	return value;
}
