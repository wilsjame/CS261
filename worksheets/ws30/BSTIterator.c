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

}

int BSTIteratorHasNext(struct BSTIterator *itr)
{

}

TYPE BSTIteratorNext(struct BSTIterator *itr)
{

}

void _slideLeft(struct Node *cur, struct BSTIterator *itr)
{

	while(cur != null)
	{
		dynArrayPush(itr->stk, cur->val);
		cur = cur->left;
	}

}
