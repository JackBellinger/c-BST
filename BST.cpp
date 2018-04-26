#include "TNode.h"
//#include "Student.h"
#include "BST.h"
#include <iostream>
using namespace std;

template <class DT>
BST<DT>::BST()
{
	root = NULL;
}

template <class DT>
BST<DT>::~BST()
{
	cleanNodes();
}

template <class DT>
TNode<DT>* BST<DT>::createNode()
{
	DT* data = new DT();
	TNode<DT>* newNode = new TNode<DT>(data);
	return newNode;
}

template <class DT>
bool BST<DT>::bstInsert()
//use this function to insert objects to the tree, so that the TNode constructor constructs the DT
{
	return bstInsert(createNode());
}

template <class DT>
bool BST<DT>::bstInsert(DT data)
//use this function for inserting primitives to a tree, because the TNode constructor initializes primitive type data to 0 / "" / NULL
{
	TNode<DT>* newNode = new TNode<DT>(data);
	return bstInsert(newNode);
}

template <class DT>
bool BST<DT>::bstInsert(TNode<DT>* newNode)
//returns true if the node was added successfully, falsse if it couldn't add it
{
	if(root == NULL)
	{
		root = newNode;
		return true;
	}
	else
	{
		TNode<DT>* current = root;
		while(current != NULL)
		{
			if(newNode->data < current->data)
			{
				if(current->left == NULL)
				{
					current->left = newNode;
					return true;
				}else
					current = current->left;
			}
			if(newNode->data > current->data)
			{
				if(current->right == NULL)
				{
					current->right = newNode;
					return true;
				}else
					current = current->right;
			}
			else if(newNode->data == current->data)
			{
				cout << "Node is already in the BST";
				return false;
			}
		}//end while
	}
	return false;//the function should never get to this statement, only if theres an error
}

template <class DT>
void BST<DT>::bstDelete(TNode<DT>*)
{
	
}

template <class DT>
TNode<DT>* BST<DT>::bstSearch(DT data)
{
	TNode<DT>* current = root;
	while(current != NULL)
	{
		if(current->data == data)
			return current;
		if(current->data < data && current->left != NULL)
			current = current->left;
		if(current->data > data && current->right != NULL)
			current = current->right;
	}
	return NULL;//if the loop exits without returning that means the data it's 	looking for isn't in the tree
}

template <class DT>
void BST<DT>::cleanNodes()
{
	cleanNodes(root);
}

template <class DT>
void BST<DT>::cleanNodes(TNode<DT>* x)
{
	if(x->left != NULL)
		cleanNodes(x->left);
	if(x->right != NULL)
		cleanNodes(x->right);
	if(x->right == NULL && x->left == NULL)
		delete x;
}

template <class DT>
TNode<DT>* BST<DT>::max()
{
	max(root);
}

template <class DT>
TNode<DT>* BST<DT>::max(TNode<DT>* max)
{
	if(max != NULL)
		while(max->right != NULL)
		{
			max = max->right;
		}
	return max;
}

template <class DT>
TNode<DT>* BST<DT>::min()
{
	min(root);
}

template <class DT>
TNode<DT>* BST<DT>::min(TNode<DT>* min)
{
	if(min != NULL)	
		while(min->left != NULL)
		{
			min = min->left;
		}
	return min;
}

template <class DT>
TNode<DT>* BST<DT>::successor()
{
	successor(root);
}

template <class DT>
TNode<DT>* BST<DT>::successor(TNode<DT>* current)
{
	return min(current->right);
}

template <class DT>
TNode<DT>* BST<DT>::predecessor()
{
	predecessor(root);
}

template <class DT>
TNode<DT>* BST<DT>::predecessor(TNode<DT>* current)
{
	return max(current->left);
}

template <class DT>
void BST<DT>::inOrder()
{
	inOrder(root);
}

template <class DT>
void BST<DT>::inOrder(TNode<DT>* current)
{
	if(current->left != NULL)
		inOrder(current->left);
	if(current != NULL)
		cout << current->data;
	if(current->right != NULL)
		inOrder(current->right);
}

template <class DT>
void BST<DT>::preOrder()
{
	preOrder(root);
}

template <class DT>
void BST<DT>::preOrder(TNode<DT>* current)
{
	if(current != NULL)
		cout << current->data;
	if(current->left != NULL)
		preOrder(current->left);
	if(current->right != NULL)
		preOrder(current->right);
}

template <class DT>
void BST<DT>::postOrder()
{
	postOrder(root);
}

template <class DT>
void BST<DT>::postOrder(TNode<DT>* current)
{
	if(current->left != NULL)
		postOrder(current->left);
	if(current->right != NULL)
		postOrder(current->right);
	if(current != NULL)
		cout << current->data;
}

//class template BST<int>;
//class template BST<Student>;
