/* Adjust heap restores heap property by percolating values 
 *
 * parameters:
 * heap: pointer to a heap
 * pos: positition index where adjustment starts (index of percolated value)
 * max: max index of the heap nodes in the dynamic Array (last value entered)
 *
 * assumptions:
 * pre: max < size
 * post: heap property is maintained for nodes from pos to index max
 */
void _adjustHeap(structdyArray *heap, int max, int pos){
	int leftChild = 2 * pos + 1;
	int rightChild = 2 * pos +2;

	if(rightChild <= max) //two children
	{
		//get index of smallest child
		int smallest = indexSmallest(heap, leftChild, rightChild);

		//if value at pos > value of smallest child
		if(dyArrayGet(heap, pos) > dyArrayGet(heap, smallest))
		{
			//swap with smallest child, call adjustHeap
			swap(heap, pos, smallest);
			_adjustHeap(heap, max, smallest);
		}

	}
	else if(leftChild <= max) //one child
	{

		if(dyArrayGet(heap, pos) > dyArrayGet(heap, leftChild))
		{
			swap(heap, pos, leftChild);
			_adjustHeap(heap, max, leftChild);
		}

	}

}

/* heapAdd adds a node to the heap
 *
 * parameters:
 * heap: pointer to a heap
 * newValue: node value
 *
 * assumptions:
 * pre: heap is not null
 * post: node is added to the heap
 */
void heapAdd(struct dyArray *heap, TYPE newValue){
	int parent;
	int pos = sizeDynArr(heap); //size index is the back of the array

	//adds to end - now need to adjust position
	addDynArr(heap, val);

	while(pos != 0)
	{
		parent = (pos - 1) / 2;

		//if the parent is greater percolate up (swap)
		if(dynArrayGet(heap, parent) > dynArrayGet(heap, pos))
		{
			swapDynArr(heap, parent, pos);
			pos = parent;
		}
		else
		{

			return;

		}

	}

}
