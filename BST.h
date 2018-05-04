#ifndef BST_H
#define BST_H
//#include "TNode.h"
#include <iostream>
using namespace std;

template <class DT>
class TNode
{

public:
	TNode* parent;
	TNode* left;
	TNode* right;
	DT data;
//public:
	TNode(DT* = new DT());
	TNode(DT);
};

template <class DT>
class BST
{
private:
	TNode<DT>* root;

	TNode<DT>* max(); 
	TNode<DT>* max(TNode<DT>*);

	TNode<DT>* min();
	TNode<DT>* min(TNode<DT>*);

	TNode<DT>* successor();
	TNode<DT>* successor(TNode<DT>*);

	TNode<DT>* predecessor();
	TNode<DT>* predecessor(TNode<DT>*);

	TNode<DT>* createNode();

	void cleanNodes();
	void cleanNodes(TNode<DT>* x);
public:
	BST();
	~BST();

	void inOrder();
	void inOrder(TNode<DT>*);

	void preOrder();
	void preOrder(TNode<DT>*);

	void postOrder();
	void postOrder(TNode<DT>*);

	bool bstInsert();
	bool bstInsert(DT);
	bool bstInsert(TNode<DT>*);

	void bstDelete(TNode<DT>*);

	TNode<DT>* bstSearch(DT data);
};
#endif
