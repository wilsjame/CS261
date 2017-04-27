#include <assert.h>
#include <stdlib.h>

#ifndef TYPE
#define TYPE int
#endif

int main(){

	return 0;

}

struct link{
	TYPE value;
	struct link *next;
};

struct listQueue{
	struct link *firstLink; /* always points to sent */
	struct link *lastLink;
};

void listQueueInit(struct listQueue *q){

	/* casting result to malloc correct type */
	struct link *lnk = (struct link *)malloc(sizeof(struct link)); /* create sentinal */
	assert(lnk != 0); /* lnk is the sentinel */
	lnk->next = 0;
	q->firstLink =  q->lastLink = lnk;
}

void listQueueAddBack(struct listQueue *q, TYPE e){
	struct link *newLink = (struct link *)malloc(sizeof(struct link));
	assert(newLink != 0);
	newLink->value = e;
	newLink->next = 0;
	q->lastLink->next = newLink;
	q->lastLink = newLink;
}

TYPE listQueueFront(struct listQueue *q){
	assert(!listQueueIsEmpty(q));

	return q->firstLink->next->value;

}

int listQueueIsEmpty(struct listQueue *q){
	
	return q->firstLink ==  q->lastLink;

}
