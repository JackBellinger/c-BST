#ifndef TNODE_H
#define TNODE_H

using namespace std;

template <class DT>
class TNode
{
//template <class DT>
//friend class BST;
public:
	TNode* parent;
	TNode* left;
	TNode* right;
	DT data;
//public:
	TNode(DT* = new DT());
	TNode(DT);
};

#endif
