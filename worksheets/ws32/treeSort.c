#ifndef
#define TYPE int
#endif

void treeSort(TYPE *data, int n){ /* sort values in array data */
	//1. copy values into tree, O(nlogn)
	//2. copy them out (into data[]) using in-order traversal, O(n)
assert(data != NULL);

	struct AVLTree tree;

	initAVLTree(&tree);

	for (int i = 0; i < n; i++)

	{

		addAVLTree(&tree, data[i]);

	}



	struct AVLIterator itr;

	AVLIteratorInit(&tree, &itr);



	int index = 0;

	while (AVLIteratorHasNext(&itr))

	{

		data[index] = AVLIteratorNext(&itr);

		index++;

	}
	
}
