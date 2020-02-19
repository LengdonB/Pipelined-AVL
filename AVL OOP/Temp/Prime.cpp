#include "Prime.h"
#include<iostream>
using namespace std;

Prime::Prime()
{
	nextFunction = NULL;
}

void Prime::setNextFunction(IPipe *nextFunction)
{
	if (this->nextFunction == NULL)
		this->nextFunction = nextFunction;
	else
		this->nextFunction->setNextFunction(nextFunction);
}

int Prime::start(int value,Node *current)
{
	bool flag = 0;
	for (int i = 2; i < value / 2; i++)
		if (value%i == 0)
			flag = 1;
	if (value == 2)
		flag = 0;
	if (flag == 0)
		cout << value << " is Prime.\n";
	else
		cout << value << " is not Prime.\n";
	if(nextFunction!=NULL)
		nextFunction->start(value,current);
	return value;
}
