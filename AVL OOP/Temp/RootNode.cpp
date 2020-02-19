#include "RootNode.h"
#include<iostream>

RootNode::RootNode()
{
	left = right = NULL;
}

void RootNode::setPipe(IPipe *pipe)
{
	nextFunction = pipe;
}
RootNode::RootNode(IPipe *pipe)
{
	left = right = NULL;
	nextFunction = pipe;
}

void RootNode::executePipe(int value, Node * current)
{
	nextFunction->start(value, current);
}

void RootNode::setLeft(Node * lft)
{
	left = lft;
}

void RootNode::setRight(Node * rt)
{
	right = rt;
}

void RootNode::setParent(Node * pa)
{
}

Node * RootNode::getLeft()
{
	return left;
}

Node * RootNode::getRight()
{
	return right;
}

Node * RootNode::getParent()
{
	return nullptr;
}