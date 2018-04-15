#include "BST.h"
#include "Student.h"
#include <iostream>

int main()
{
	BST<int>* bst = new BST<int>();	
	bst->bstInsert(4);
	bst->bstInsert(3);
	bst->bstInsert(5);
	bst->bstInsert(7);
	bst->inOrder();
	
	
	return 0;
}

