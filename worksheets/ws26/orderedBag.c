#include <assert.h>
/* Assume access to all existing dynArr functions */
/* _binarySearch is also included in dynArr.c now as an internal function! */
int _binarySearch(TYPE *data, int size, TYPE testValue);

/* New functions to take advantage of the ordered dynamic array
 * and available to the end user, so they will be declared in the .h file */

int dynArrayBinarySearch(struct dyArray *da, TYPE testValue){
	return _binarySearch(da->data, da->size, testValue); 
}

void orderedArrayAdd(struct dyArray *da, TYPE newElement){
	int index = _binarySearch(da->data, da->size, newElement);
	/* takes care of resize if necessary */
	dyArrayAddAt(da, index, newElement);
}

/* Complete these */
/* returns 1 if the array contains the element and 0 otherwise */
int orderedArrayContains(struct dyArray *da, TYPE testElement){
	assert(da != 0);

	int binReturn = _binarySeach(da->data, da->size, testElement);
	
	if(binReturn >= da->size){

		return 0;

	}
	else if(da->data[binReturn] != testElement){

		return 0;

	}
	else{

		return 1;

	}

}

void orderedArrayRemove(struct dyArray *da, TYPE testElement){
	assert(da != 0);

	int binReturn = _binarySeach(da->data, da->size, testElement);

	if(orderArrayContains(da, testElement)){

		removeAtDynArray(da, binReturn);

	}

}
