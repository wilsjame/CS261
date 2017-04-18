#include <stdlib.h>
#include <assert.h>
#ifndef TYPE
#define TYPE int
#endif

struct DynArr{
	TYPE *data;	/* pointer to the data array */
	int size;	/* number of elements in the array */
	int capacity;	/* max size of the array */
};

void initDynArr(struct DynArr *v, int capacity){
	v->data = malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);	/* good practice */

	v->size = 0;
	v->capacity = capacity;
}

void freeDynArr(struct DynArr *v){

	if(v->data != 0){
		free(v->data);	/* free space on the heap */
		v->data = 0;	/* make it point to null */
	}

	v->size = 0;
	v->capacity = 0;
}

int sizeDynArr(struct DynArr *v){
	return v->size;
}

/* _setCapacityDynArr creates a new array double the original capacity, 
 * copies the original elements over, and free's the original array */
void _setCapacityDynArr(struct DynArr *v, int newCap){
	int index;

	/* allocate new array */
	struct DynArr newArray;
	initDynArr(&newArray, newCap);

	/* copy old data */
	for(index = 0; index < v->size; index++){
		newArray.data[index] = v->data[index];
		newArray.size++;
	}

	/* free old data from the heap */
	freeDynArr(v);
	
	/* change pointer to reference new array */
	*v = newArray;
}

void addDynArr(struct DynArr *v, TYPE val){
	/* check is resize is necessary */
	if(v->size >= v->capacity){
		_setCapacityDynArr(v, 2 * v->capacity);
	}

	v->data[v->size] = val;
	v->size++;
}

TYPE getDynArr(struct DynArr *da, int position){
	/* check if indexed position is legal and positive */
	assert(position >= 0 && position < da->size);

	return da->data[position];

}

void putDynArr(struct DynArr *da, int position, TYPE value){
	int index;

	/* check if indexed position is legal and positive */
	assert(position >= 0 && position < da->size);
	assert(da->size + 1 <= da->capacity);

	/* shift elements at position */
	for(index = da->size; index > position; index--){
		da->data[index] = da->data[index - 1];
	}

	/* insert value at position */
	da->data[position] = value;
	da->size++;
}

void swapDynArr(struct DynArr *da, int i, int j){
	assert(i >= 0 && j >= 0 && i < da->size && j < da->size);

	TYPE temp = da->data[i];
	da->data[i] = da->data[j];
	da->data[j] = temp;
}

void removeAtDynArr(struct DynArr *da, int index){
	int indexArr;

	assert(index >= 0 && index < da->size);

	/* delete element at index */
	da->data[index] = 0;

	/* shift elements */
	for(indexArr = index; indexArr < da->size; indexArr++){ 
		da->data[indexArr] = da->data[indexArr + 1];
	}

	da->size--;
}
