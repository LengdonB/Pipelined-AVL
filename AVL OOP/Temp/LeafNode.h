#pragma once
#include "INode.h"
#include"IPipe.h"


/// <summary>
/// The class LeafNode represents the instances of nodes that are external i.e. they only have a parent pointer; 
/// </summary>
/// <seealso cref="Node" />
class LeafNode :
	public Node
{
private:
	Node *parent;	
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="LeafNode"/> class.
	/// </summary>
	LeafNode();
	LeafNode(IPipe *pipe);
	void executePipe(int value, Node *current);
	void setPipe(IPipe *pipe);//manually define a pipe for the node
	void setLeft(Node *lft);
	void setRight(Node* rt);
	/// <summary>
	/// Sets the parent.
	/// </summary>
	/// <param name="pa">The pa.</param>
	void setParent(Node* pa);
	Node* getLeft();
	Node* getRight();
	Node* getParent();
};

