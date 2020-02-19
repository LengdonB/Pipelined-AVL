#pragma once
#include "INode.h"
#include"IPipe.h"
/// <summary>
/// class RootNode represents the first node. It can have left and right child but it cannot have a parent.
/// </summary>
/// <seealso cref="Node" />
class RootNode :
	public Node
{
private:

	Node *left, *right;
	
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="RootNode"/> class.
	/// </summary>
	RootNode();
	/// <summary>
	/// Initializes a new instance of the <see cref="RootNode"/> class.
	/// </summary>
	/// <param name="pipe">The pipe.</param>
	RootNode(IPipe *pipe);
	/// <summary>
	/// Executes the pipe.
	/// </summary>
	/// <param name="value">The value.</param>
	/// <param name="current">The current.</param>
	void executePipe(int value, Node *current);
	void setPipe(IPipe *pipe);//manually define a pipe for the node	
/// <summary>
/// Sets the left.
/// </summary>
/// <param name="lft">The LFT.</param>
	void setLeft(Node *lft);
	/// <summary>
	/// Sets the right.
	/// </summary>
	/// <param name="rt">The rt.</param>
	void setRight(Node* rt);
	/// <summary>
	/// Sets the parent.
	/// </summary>
	/// <param name="pa">The pa.</param>
	void setParent(Node* pa);
	/// <summary>
	/// Gets the left.
	/// </summary>
	/// <returns></returns>
	Node* getLeft();
	/// <summary>
	/// Gets the right.
	/// </summary>
	/// <returns></returns>
	Node* getRight();
	/// <summary>
	/// Gets the parent.
	/// </summary>
	/// <returns></returns>
	Node* getParent();
};