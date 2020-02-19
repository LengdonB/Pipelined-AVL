#pragma once
#include<iostream>
#include"RootNode.h"
#include"InternalNode.h"
#include"LeafNode.h"

/*
The class Bst 
*/
/// <summary>
/// The class BST is a Binary Search Tree.
/// The following functions are available: 1.Traversals(preorder, postorder, inorder)
/// 2. Insert elements 3. Search an element 4. Calculate tree height.
/// </summary>
class Bst
{
protected:
	Node *root;
	Node* findParent(Node* current, int value);
	int postOrder(Node* current);
	int inOrder(Node*current);
	int findTreeHeight(Node *current);
	void assignBF(Node* current);
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Bst"/> class.
	/// </summary>
	Bst();
	/// <summary>
	/// Inserts the specified value.
	/// </summary>
	/// <param name="value">The value.</param>
	/// <param name="pipe">The pipe.</param>
	/// <returns></returns>
	Node* Insert(int value, IPipe* pipe);
	/// <summary>
	/// Searches the specified value.
	/// </summary>
	/// <param name="value">The value.</param>
	/// <returns></returns>
	bool search(int value);
	/// <summary>
	/// Finds the height of the tree.
	/// </summary>
	/// <returns></returns>
	int findTreeHeight();
	/// <summary>
	/// Inorder traversal of tree.
	/// </summary>
	void inOrder();//inorder traversal
/// <summary>
/// Postorder traversal of tree.
/// </summary>
	void postOrder();//postorder traversal
};

