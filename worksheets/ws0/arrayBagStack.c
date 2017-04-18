#include "arrayBagStack.h"
#include <assert.h>

int main(){

	return 0;

}

void initArray(struct arrayBagStack * b){
	b->count = 0;
}

/* Bag Interface Functions */
/* *********************** */
void addArray(struct arrayBagStack * b, TYPE v){

	if(b->count < 100){
		b->data[b->count] = v;
		b->count++;
	}
	else{
		/* bag is full */
	}

}

/* containsArray returns 1 if the item is found and 0 otherwise */
int containsArray(struct arrayBagStack * b, TYPE v){
	int index;

	for(index = 0; index < b->count; index++){
		if(v == b->data[index]){

			return 1;

		}
	}

	return 0;
}

void removeArray(struct arrayBagStack * b, TYPE v){
	int index;

	if(b->count > 0){
		for(index = 0; index < b->count; index++){
			if(v == b->data[index]){
				b->data[index] = 0;
				b->count--;
			}
		}
	}

}

int sizeArray(struct arrayBagStack * b){

	return b->count;

}

/* Stack Interface Functions */
/* ************************* */
void pushArray(struct arrayBagStack * b, TYPE v){

	if(b->count > 0 && b->count < 100){
		b->data[b->count] = v;
		b->count++;
	}
	else{
		/* stack is full */
	}

}

TYPE topArray(struct arrayBagStack * b){
	assert(b->count != 0);

	return b->data[b->count -1];

}


void popArray(struct arrayBagStack * b){
	assert(b->count != 0);
	b->data[b->count - 1] = 0;
	b->count--;
}

/* isEmptyArray return 1 if the array is empty and 0 otherwise */
int isEmptyArray(struct arrayBagStack * b){

	if(b->count == 0){
		return 1;
	}
	else{
		return 0;
	}

}
