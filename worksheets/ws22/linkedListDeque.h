#include <stdlib.h>
#include <assert.h>

#ifndef TYPE
#define TYPE int
#endif

struct dlink{
	TYPE value;
	struct dlink *next;
	struct dlink *prev;
};

struct linkedList{
	int size;
	struct dlink *frontSentinal;
	struct dlink *backSentinal;
};

/* provided function */
/*********************/

void linkedListInit(struct linkedList *q){

	q->frontSentinal = malloc(sizeof(struct dlink));
	assert(q->frontSentinal != 0 );

	q->backSentinal = malloc(sizeof(struct dlink));
	assert(q->backSentinal != 0);

	q->frontSentinal->next = q->backSentinal;
	q->backSentinal->prev = q->frontSentinal;
	q->size = 0;
}

/* write these functions */
/*************************/

/* _addBefore places a new link BEFORE the provide link, lnk */
void _addBefore(struct linkedList *q, struct dlink *lnk, TYPE e){
	struct dlink *newLink = malloc(sizeof(struct dlink));
	assert(newLink != 0);
	lnk->prev->next = newLink;
	lnk->prev = newLink;
	newLink->next = lnk;
	newLink->prev = lnk->prev;
	newLink->value = e;

	q->size++;
}

void _removeLink(struct linkedList *q, struct dlink *lnk){
	assert(q->size > 0);
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	free(lnk);

	q->size--;
}

TYPE linkedListFront(struct linkedList *q){
	assert(!linkedListIsEmpty(q));

	return q->frontSentinal->next->value;

}

TYPE linkedListBack(struct linkedList *q){
	assert(!linkedListIsEmpty(q));

	return q->backSentinal->prev->value;

}

/* provided functions */
/*********************/

int linkedListIsEmpty(struct linkedList *q){

	return q->size == 0;

}

void linkedListRemoveFront(struct linkedList *q){
	assert(!linkedListIsEmpty(q));
	_removeLink(q, q->frontSentinal->next);

	assert(!linkedListIsEmpty(q));
	_removeLink(q, q->backSentinal->prev);
}

void linkedListFree(struct linkedList *q){

	while(q->size > 0){
		linkedListRemoveFront(q);
	}

	free(q->frontSentinal);
	free(q->backSentinal);
	q->frontSentinal = q->backSentinal = 0;
}

void linkedListAddFront(struct linkedList *q, TYPE e){
	_addBefore(q, q->frontSentinal->next, e);
}

void linkedListAddBack(struct linkedList *q, TYPE e){
	_addBefore(q, q->backSentinal, e);
}
