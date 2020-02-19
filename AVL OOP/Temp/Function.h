#pragma once
#include<iostream>
#include"RootNode.h"
#include"InternalNode.h"
#include"LeafNode.h"
using namespace std;
/// <summary>
/// IFunction is an abstract class for pipelining that other classes can inherit.
/// </summary>
class IFunction
{
public:
	virtual void setSuccessor(IFunction *) = 0;
	virtual int Start(Node* current, int value) = 0;
};