#pragma once
#include "Bst.h"

/// <summary>
/// The class AVL represents the AVL tree which is a self balancing Binary Search Tree. On inserting elements it automatically tries to balance its height by readjusting its height while maintaining BST property
/// </summary>
/// <seealso cref="Bst" />
class AVL :
	public Bst
{
private:
	Node *leftRotation(Node* current, IPipe* pipe);
	Node *rightRotation(Node* current,IPipe *pipe);
	void Balance(Node* current,IPipe *pipe);
public:
	/// <summary>
	/// Insert element into the AVL tree.
	/// </summary>
	/// <param name="value">The value.</param>
	/// <param name="pipe">The pipe.</param>
	void avlInsert(int value, IPipe* pipe);
};