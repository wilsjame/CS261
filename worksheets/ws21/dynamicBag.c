#include "dynamicArray.h"

int main(){

	return 0;

}

void removeDynArr(struct DynArr *da, TYPE test){
	int index;

	for(index = 0; index < da->size; index++){
		if(test == da->data[index]){ /* found it */
			removeAtDynArr(da, index);
			return;
		}
	}

}

/* containDynArr returns 1 if the value is in the bag and 0 otherwise */
int containsDynArr(struct DynArr *da, TYPE e){
		int index;

	for(index = 0; index < da->size; index++){
		if(e == da->data[index]){ /* found it */
			return 1;
		}
	}

	return 0;

}
