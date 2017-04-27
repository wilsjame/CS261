#include <stdlib.h>
#include <assert.h>

#ifndef TYPE
#define TYPE int
#endif

int main(){

	return 0;

}

struct deque{
	TYPE *data; /* pointer to data array */
	int capacity; /* number of elements in collection */
	int size; /* index of first logical element */
	int beg; /* capacity of array */
};

void dequeInit(struct deque *d, int initCapacity){
	assert(initCapacity > 0);
	d->data = (TYPE *)malloc(initCapacity * sizeof(TYPE));
	assert(d->data != 0);

	d->size = d->beg = 0; /* logical index zero is the actual index zero */
	d->capacity = initCapacity;
}

void _dequeSetCapacity(struct deque *d, int newCap){
	int i;

	/* create new underlying array */
	TYPE *newData = (TYPE*)malloc(newCap * sizeof(TYPE));
	assert(newData != 0);

	/* copy elements to it */
	int j = d->beg;

	for(i = 0; i < d->size; i++){
		j = j + 1;
		if(j >= d->capacity){
			j = 0;
		}
	}

	/* delete the old underlying array */
	free(d->data);

	/* update capacity and size and data */
	d->data = newData;
	d->capacity = newCap;
	d->beg = 0;
}

void dequeFree(struct deque *d){
	free(d->data);
	d->size = 0;
	d->capacity = 0;
}

int dequeSize(struct deque *d){

	return d->size;

}

/* write these functions */
/*************************/

void dequeAddFront(struct deque *d, TYPE newValue){
	/* check if there is space for it */
	/* double capacity if full */
	if(d->size >= d->capacity){
		_dequeSetCapacity(d, 2 * d->capacity);
	}

	/* check if the start of array is the actual start */
	if(d->beg == 0){
		d-> beg = d->capacity - 1;
	}
	else{
		d->beg = d->beg - 1;
	}

	d->data[d->beg] = newValue;
	d->size++;
}

/* put value in the back of the deque */
void dequeAddBack(struct deque *d, TYPE newValue){
	int index;

	/* check if there is space for it */
	/* double capacity if full */
	if(d->size >= d->capacity){
		_dequeSetCapacity(d, 2 * d->capacity);
	}

	index = d->beg + d->size; /* compute proper index */

	if(index >= d->capacity){
		index -= d->capacity; /* wrap around */
	}

	d->data[index] = newValue;
	d->size++;

	/* alternate method 
	d->data[(d->beg + d->size) % d->capacity] = newValue;
	d->size++;
	*/
}

/* return the front value in the deque */
TYPE dequeFront(struct deque *d){
	assert(d->size > 0);

	return d->data[d->beg];

}

/* return the back value in the deque */
TYPE dequeback(struct deque *d){
	assert(d->size > 0);
	/*compute proper index */
	int index = d->beg + d->size - 1; /* w/out '-1' return empty element next to back */ 
	
	if(index > d->capacity){
		index -= d->capacity; /* wrap around */
	}

	return d->data[index];

	/* alternate method
	d->data[(d->beg + d->size) % d->capacity] = newValue;
	*/
}

void dequeRemoveFront(struct deque *d){
	assert(d->size > 0);
	d->beg = (d->beg + 1) % d->capacity;
	d->size--;
}

void dequeRemoveBack(struct deque *d){
	assert(d->size > 0);
	d->size--;
}
