#include "InternalNode.h"
#include<iostream>

InternalNode::InternalNode(IPipe * pipe)
{
	left = right = parent = NULL;
	nextFunction = pipe;
}

void InternalNode::setPipe(IPipe * pipe)
{
	nextFunction = pipe;
}

void InternalNode::executePipe(int value, Node *current)
{
	nextFunction->start(value,current);
}

InternalNode::InternalNode()
{
	left = right = parent = NULL;
}

void InternalNode::setLeft(Node *lft)
{
	left = lft;
}

void InternalNode::setRight(Node* rt)
{
	right = rt;
}

void InternalNode::setParent(Node * pa)
{
	parent = pa;
}

Node * InternalNode::getLeft()
{
	return left;
}

Node * InternalNode::getRight()
{
	return right;
}

Node * InternalNode::getParent()
{
	return parent;
}