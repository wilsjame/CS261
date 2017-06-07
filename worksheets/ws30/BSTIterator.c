#ifndef
#define TYPE int
#endif

/* assume we have already defined a Stack that will hold pointers to nodes,
 * show the implementation of the function that implement the iterator
 * algorithms described above. */

struct BSTIterator
{
	struct DynArr *stk;
	struct BSTree *tree;
};

void BSTIteratorInit(struct BSTree *tree, struct BSTIterator *tr)
{
	itr->stack = (struct DynArr *)malloc(sizeof(struct DynArr));
	initDynArr(itr->stk, 4);

	itr->tree = tree;

}

int BSTIteratorHasNext(struct BSTIterator *itr)
{

	if(itr->stack->size != 0) //if stack is empty
	{
		//slide left on root
		_slideLeft(itr->tree->root, itr);
	}
	else
	{
		//let n be top of stack, pop topmost element
		struct Node *n = topDynArray(itr->stack);
		popDynArray(itr->stk);
		//slide left on right child of n
		_slideLeft(n->right, itr);
	}	
	

	//return true if the stack is not empty
	return !isEmptyDynArray(itr->stack);
	
}

TYPE BSTIteratorNext(struct BSTIterator *itr)
{
	struct Node* returnMyValue = dynArrayPop(itr->stk);
	
	return returnMyValue->value;
	
}

void _slideLeft(struct Node *cur, struct BSTIterator *itr)
{

	while(cur != null)
	{
		dynArrayPush(itr->stk, cur->val);
		cur = cur->left;
	}

}
