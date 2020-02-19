#include "LeafNode.h"
#include<iostream>
//initializes the instance of LeafNode
LeafNode::LeafNode()
{
	parent = NULL;
}

LeafNode::LeafNode(IPipe * pipe)
{
	parent = NULL;
	nextFunction = pipe;
}

void LeafNode::executePipe(int value, Node * current)
{
	nextFunction->start(value, current);
}

void LeafNode::setPipe(IPipe * pipe)
{
	nextFunction = pipe;
}

void LeafNode::setLeft(Node * lft)
{
}

void LeafNode::setRight(Node * rt)
{
}

void LeafNode::setParent(Node * pa)
{
	parent = pa;
}

Node * LeafNode::getLeft()
{
	return nullptr;
}

Node * LeafNode::getRight()
{
	return nullptr;
}

Node * LeafNode::getParent()
{
	return parent;
}
