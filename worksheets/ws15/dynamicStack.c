#include "dynamicArray.h"
#include <assert.h>

int main(){

	return 0;

}

/* Dynamic Array implementation of the Stack Interface */
void pushDynArray(struct DynArr *da, TYPE e){
	addDynArr(da, e);
}

TYPE topDynArray(struct DynArr *da){
	assert(da->size >= 1);

	return getDynArr(da, da->size-1);

}

void popDynArray(struct DynArr *da){
	assert(da->size >= 1);

	removeAtDynArr(da, da->size - 1);
}

/* isEmptyDynArray returns 1 if the stack is empty and 0 otherwise */
int isEmptyDynArray(struct DynArr *da){

	if(da->size == 0){

		return 1;

	}

	return 0;

}
