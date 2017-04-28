#include "linkedListDeque.h"
#include <assert.h>

#ifndef EQ
#define EQ(A, B) ((A) == (B))
#endif

int main(){

	return 0;

}

void linkedListAdd(struct linkedList *lst, TYPE e){
	_addBefore(lst, lst->frontSentinal->next, e);
}

/* linkedListContains returns 1 if the value e is found and o otherwise */
int linkedListContains(struct linkedList *lst, TYPE e){
	assert(!linkedListIsEmpty(lst));

	/* create iterator link */
	struct dlink *iterator = lst->frontSentinal->next;

	while(iterator != lst->backSentinal){

		if(EQ(iterator->value,e)){

			return 1; /* found it */
		}

		iterator = iterator->next;
	}

	return 0;

}

void linkedListRemove(struct linkedList *lst, TYPE e){
	assert(!linkedListIsEmpty(lst));

	/* create iterator link */
	struct dlink *iterator = lst->frontSentinal->next;

	while(iterator != lst->backSentinal){

		if(EQ(iterator->value,e)){

			_removeLink(lst, iterator); /* found it */
		}

		iterator = iterator->next;
	}

}
