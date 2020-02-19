#pragma once
#include "INode.h"
#include "IPipe.h"
/// <summary>
/// The class InternalNode represents nodes that has child nodes as well as parent node
/// </summary>
/// <seealso cref="Node" />
class InternalNode :
	public Node
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="InternalNode"/> class.
	/// </summary>
	InternalNode();
	/// <summary>
	/// Initializes a new instance of the <see cref="InternalNode"/> class.
	/// </summary>
	/// <param name="pipe">The pipe.</param>
	InternalNode(IPipe *pipe);
	/// <summary>
	/// Sets the pipe.
	/// </summary>
	/// <param name="pipe">The pipe.</param>
	void setPipe(IPipe *pipe);//manually define a pipe for the node
/// <summary>
/// Executes the pipe.
/// </summary>
/// <param name="value">The value.</param>
/// <param name="current">The current.</param>
	void executePipe(int value, Node *current);
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
private:
	Node *left, *right, *parent;
};