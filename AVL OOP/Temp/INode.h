#pragma once

class IPipe;//forward declaration
/// <summary>
/// Node is an abstract class which can be inherited by different child classes and overwritten.
/// </summary>
class Node {
public:
	/// <summary>
	/// The balanceF keeps track of the balance factor associated with a node
	/// </summary>
	int balanceF = 0;//balance factor
/// <summary>
/// The key stores value of the node
/// </summary>
	int key = 0;
	virtual Node* getLeft() = 0;
	virtual Node* getRight() = 0;
	virtual Node* getParent() = 0;
	virtual void setLeft(Node * lft) = 0;
	virtual void setRight(Node * rt) = 0;
	virtual void setParent(Node * pt) = 0;
	virtual void executePipe(int value, Node *current)=0;
	 IPipe *nextFunction;
};