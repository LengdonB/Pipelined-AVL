#include "AVL.h"
Node * AVL::rightRotation(Node * current,IPipe *pipe)
{
	Node *sup;
	sup = current->getParent();
	RootNode *newRoot = new RootNode();//if parent is root node then after rotation child will become the new root.
	newRoot->nextFunction=current->nextFunction;
	if (sup == root)//parent is root node then after rotation child will become root
	{
		/*
		If parent is root then after rotation if parent has child then it becomes internal node ,
		otherwise it becomes leaf. This is checked later in the program.
		*/
		root = newRoot;
		newRoot->key = current->key;
		current->setParent(NULL);
	}
	else
	{
		//current is the node that is to be rotated
		if (typeid(current) == typeid(LeafNode))//if node to be rotated is leaf then convert it to internal
		{
			InternalNode *temp = new InternalNode();//temp is new internal node for the inserted node
			temp->key = current->key;
			temp->nextFunction = current->nextFunction;
			temp->setParent(current->getParent());
			sup->setLeft(temp);
			current->setParent(NULL);//removing parent pointer of leaf node
			current = temp;//now new node is internal
		}

		//if parent is right child of grand parent then connects grand parent to child(current)
		if (sup->key > sup->getParent()->key)
		{
			sup->getParent()->setRight(current);
			current->setParent(sup->getParent());
		}
		else//if parent is the left child connects grand parent to child(current)
		{
			(sup->getParent())->setLeft(current);
			current->setParent(sup->getParent());
		}
	}
	sup->setLeft(NULL);//disconnect left node of parent to child 

	if (current->getRight() != NULL)//if child has a right subtree, connect it to parent's left child
	{
		sup->setLeft(current->getRight());
		sup->getLeft()->setParent(sup);
	}

	if (sup->getLeft() == NULL && sup->getRight() == NULL)//if parent has no child then after rotation it becomes leaf node
	{
		LeafNode *temp = new LeafNode();
		temp->setPipe(pipe);
		temp->setParent(sup->getParent());
		temp->key = sup->key;
		sup = temp;
	}
	else//if parent has child then it will become internal node
	{
		InternalNode *temp = new InternalNode();
		temp->nextFunction = sup->nextFunction;
		temp->key = sup->key;
		temp->setLeft(sup->getLeft());
		temp->setRight(sup->getRight());
		sup = temp;
	}
	if (root == newRoot)//if the parent node was root then after rotation child will become root.
	{
		newRoot->setLeft(current->getLeft());
		newRoot->setRight(current->getRight());
		newRoot->getLeft()->setParent(newRoot);
		newRoot->getRight()->setParent(newRoot);
		current = newRoot;
	}
	//Make the parent right child of the child node
	sup->setParent(current);
	current->setRight(sup);

	return current;//returns the node after rotation
}

Node * AVL::leftRotation(Node * current, IPipe* pipe)
{
	Node *sup;
	sup = current->getParent();

	if (sup == root)//parent is root node then after rotation child will become root
	{
		/*
		If parent is root then after rotation if parent has left child then it becomes internal node ,
		otherwise it becomes leaf.
		*/
		RootNode *temp = new RootNode();//after rotation new node will become root
		root = temp;
		temp->nextFunction=current->nextFunction;
		temp->key = current->key;
		current->setParent(NULL);
	}
	else {
		if (typeid(current) == typeid(LeafNode))//if child to be rotated is leaf then convert it to internal
		{
			InternalNode *temp = new InternalNode();//temp is new internal node for the inserted node
			temp->nextFunction = current->nextFunction;
			temp->key = current->key;
			temp->setParent(current->getParent());
			sup->setRight(temp);
			current->setParent(NULL);//removing parent pointer of leaf node
			current = temp;//now new node is internal
		}

		if (sup->key > sup->getParent()->key)//if parent is right child of grand parent
		{
			//connects grand parent to child(current)
			sup->getParent()->setRight(current);
			current->setParent(sup->getParent());
		}
		else//if parent is the left child
		{
			sup->getParent()->setLeft(current);
			current->setParent(sup->getParent());
		}
	}
	sup->setRight(NULL);//disconnect right node of parent to child 

	if (current->getLeft() != NULL)//if child has a left subtree, connect it to parent's right child
	{
		sup->setRight(current->getLeft());
		sup->getRight()->setParent(sup);
	}

	if (sup->getLeft() == NULL && sup->getRight() == NULL)//if parent has no child then after rotation it becomes leaf node
	{
		LeafNode *temp = new LeafNode();
		temp->nextFunction = sup->nextFunction;
		temp->setParent(sup->getParent());
		sup = temp;
	}
	//Make the parent left child of the child node
	sup->setParent(current);
	current->setLeft(sup);

	return current;
}
void AVL::Balance(Node * current, IPipe *pipe)//The current is passed as parameter is the address of the
{
	assignBF(current);//assigns balancing factor to all the nodes upto root.
	int bfParent = 0;//Balancing factor of the parent
	int bfChild = 0;//Balancing factor of the child

	//loop checks from newly inserted leaf till root if any node is unbalanced and stops there
	while (current != root)
	{
		bfChild = current->balanceF;
		current = current->getParent();
		bfParent = current->balanceF;
		if (bfParent == 2 || bfParent == -2)
			break;
	}
	Node *parent;
	parent = current;//parent to keep track of unbalanced node
	//Rotations
	if (bfParent == -2 && bfChild == -1)//RR Rotation
	{
		current = current->getRight();
		leftRotation(current,pipe);
	}
	else if (bfParent == 2 && bfChild == 1)//LL
	{
		current = current->getLeft();
		rightRotation(current,pipe);
	}
	else if (bfParent == 2 && bfChild == -1)//LR
	{
		current = current->getLeft()->getRight();
		leftRotation(current,pipe);
		rightRotation(current,pipe);
	}
	else if (bfParent == -2 && bfChild == 1)//RL
	{
		current = current->getRight()->getLeft();
		rightRotation(current,pipe);
		leftRotation(current,pipe);
	}
}

void AVL::avlInsert(int value, IPipe* pipe)
{
	Node* addOfInsertedElement=Insert(value, pipe);//Address of inserted element is recovered from the inserted function
	Balance(addOfInsertedElement,pipe);//Balances the tree
}

