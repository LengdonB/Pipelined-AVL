#include "Pipeline.h"
#include<iostream>

Pipeline::Pipeline()
{
	nextFunction=NULL;
}

void Pipeline::setNextFunction(IPipe *nextFunction)
{
	if (this->nextFunction == NULL)
		this->nextFunction = nextFunction;
	else
		this->nextFunction->setNextFunction(nextFunction);
}

int Pipeline::start(int value, Node * current)
{
	if(this->nextFunction!=NULL)
		this->nextFunction->start(value, current);
	return value;
}
