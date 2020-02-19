#include "EvenOddPair.h"
#include<iostream>
using namespace std;
EvenOddPair::EvenOddPair()
{
	nextFunction = NULL;
}
void EvenOddPair::setNextFunction(IPipe * nextFunction)
{
	if (this->nextFunction == NULL)
		this->nextFunction = nextFunction;
	else
		this->nextFunction->setNextFunction(nextFunction);
}

int EvenOddPair::start(int value, Node * current)
{
	if (current != NULL && current->getParent() != NULL)//Checks if current node and its parent are present
	{
		//checks if current node and parent node are both even.
		if (current->key % 2 == 0 && current->getParent()->key % 2 == 0)
			cout << "Even-Even" << endl;
		else//checks if current node and parent node are both odd.
			if (current->key % 2 != 0 && current->getParent()->key % 2 != 0)
				cout << "Odd-Odd" << endl;
	}
	if (nextFunction != NULL)
		nextFunction->start(value, current);
	return value;
}
