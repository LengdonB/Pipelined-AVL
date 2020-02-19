#include "Bst.h"
#include<algorithm>
#include<iostream>
using namespace std;
//Finds suitable of the node that is to be inserted
Node * Bst::findParent(Node * current, int value)
{
	
	if (current == NULL)//if starting node in NULL/root is not initialized
	{
		return NULL;
	}
	while (current != NULL)
	{
		current->executePipe(value, current);
		if (current->key == value)
			return current;
		if (value < current->key)
		{
			if (current->getLeft() == nullptr)
				return current;
			else
			{
				current = current->getLeft();
			}
		}
		else
			if (current->getRight() == nullptr)
				return current;
			else
			{  
				current = current->getRight();
			}
	}
	
	return current;
}

int Bst::postOrder(Node* current)
{
	if (current == NULL)
		return NULL;
	postOrder(current->getLeft());
	postOrder(current->getRight());
	cout << current->key << " ";
}

int Bst::inOrder(Node * current)
{
	if (current == NULL)
		return NULL;
	inOrder(current->getLeft());
	cout << current->key << " ";
	inOrder(current->getRight());
	
}
int Bst::findTreeHeight(Node * current)
{
	if (current == NULL)
		return 0;
	return 1 + max(findTreeHeight(current->getRight()), findTreeHeight(current->getLeft()));
}
void Bst::assignBF(Node *current)
{
	
		while (current!= root)//Re balancing all nodes from leaf till root
		{
			current->balanceF = (findTreeHeight(current->getLeft()) - findTreeHeight(current->getRight()));
			current = current->getParent();
		}
		current->balanceF = (findTreeHeight(current->getLeft()) - findTreeHeight(current->getRight()));
}


void Bst::inOrder()
{
	inOrder(root);
}
	

void Bst::postOrder()
{
	postOrder(root);
}

Bst::Bst()
{
	root = NULL;
}
Node * Bst::Insert(int value, IPipe* pipe)
{
	Node *parent;
	//Searches for the leaf node below which new node will insert
	parent = findParent(root, value);
	if (parent == NULL)//If Root node is not present, new Node becomes the Root
	{
		RootNode *temp = new RootNode(pipe);
		temp->key = value;
		
		root = temp;
		return root;
	}
	else//if root node is present
	{
		if (parent->key == value)//if value already exist then only update its pipe
		{
			parent->nextFunction = pipe;
			return parent;
		}
		//new node is always inserted at the end so new node must be a leaf node
		LeafNode* temp = new LeafNode(pipe);
		temp->key = value;

		/*Either of Three conditions can happen:
			i)Parent of the node to be inserted is root, then node is directly inserted.
			ii)Parent of the inserted Node can be an internal Node, then insert directly.
			iii)Parent of the inserted Node can be an Leaf Node, then convert parent to Internal first then insert.
		*/
		if (typeid(*parent) == typeid(RootNode))//if parent is root
		{
			temp->setParent(parent);
			if (value < parent->key)
			{
				parent->setLeft(temp);
			}
			else
				parent->setRight(temp);
		}
		else
		{
			//parent node can be leaf or internal node
			if (typeid(*parent) == typeid(LeafNode))//if parent is leaf node then we convert it to internal node
			{
				InternalNode* internal = new InternalNode(parent->nextFunction);
				internal->key = parent->key;
				internal->setParent(parent->getParent());//setting the parent of internal node
				if (internal->key < (parent->getParent())->key)//checks internal node of left or right child of its parent.
					(internal->getParent())->setLeft(internal);
				else
					internal->getParent()->setRight(internal);
				parent = internal;//internal node is now the parent of newly inserted node
			}
			Node *current;
			current = temp;
			//connect newly inserted leaf node to parent
			current->setParent(parent);
			if (value < parent->key)//checks if new node is left or right child
				parent->setLeft(current);
			else
				parent->setRight(current);

			return current;
		}
	}
}
bool Bst::search(int value)
{
	Node* temp=findParent(root, value);
	if (temp->key == value)
		return true;
	else
		return false;
}
int Bst::findTreeHeight()
{
	return findTreeHeight(root);
}
//Function to insert node by serching the parent to the node to be inserted. Search function also calls pipelined methods

