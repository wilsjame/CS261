#include "dynamicArray.h"
#include <assert.h>

int main(){

	return 0;

}

void removeAtDynArr(struct DynArr *da, int index);

struct dynArrayIterator{
	struct DynArr *da;
	int currentIndex;
};

void dynArrayIteratorInit(struct DynArr *dy, struct dynArrayIterator *itr){
	assert(dy != 0);
	assert(itr !=0);

	itr->currentIndex = 0;
	itr->da = dy;
}

/* returns 1 if the next array value is valid and 0 otherwise */
int dynArrayIteratorHasNext(struct dynArrayIterator *itr){

	if(itr->currentIndex < itr->da->capacity){

		return 1;

	}
	else
	{

		return 0;

	}

}

/* increments the index and returns the value */
TYPE dynARrayIteratorNext(struct dynArrayIterator *itr){

	return itr->da->data[itr->currentIndex++]; /* increment counter */

}

/* always call remove after next, dont call remove twice in a row */
void dynArrayIteratorRemove(struct dynArrayIterator *itr){

	removeAtDynArr(itr->da, itr->currentIndex);
	itr->currentIndex--; /*decrement counter */

}
