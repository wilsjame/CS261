#include <assert.h>
#include <stdlib.h>

#ifndef TYPE
#define TYPE  int
#endif

int main(){

	return 0;

}

struct link{
	TYPE value;
	struct link *next;
};

struct linkedListStack{
	struct link *firstLink;
};

void linkedListStackInit(struct linkedListStack *s){
	s->firstLink = 0;
}

/* linkedListStackIsEmpty returns 1 if the stack is empty and 0 otherwise */
int linkedListStackIsEmpty(struct linkedListStack *s){
	
	if(s->firstLink == 0){

		return 1;

	}

	return 0;

}

/* linkedListStackTop returns the value in the firstLink */
TYPE linkedListStackTop(struct linkedListStack *s){
	
	return s->firstLink->value;

}

void linkedListStackPop(struct linkedListStack *s){
	s->firstLink = s->firstLink->next;
	s->firstLink = 0;
}

void linkedListStackFree(struct linkedListStack *s){
	
	while(!linkedListStackIsEmpty(s)){
		linkedListStackPop(s);
	}

}

void linkedListStackPush(struct linkedListStack *s, TYPE d){
	struct link *newLink = malloc(sizeof(struct link));
	assert(newLink != 0);
	newLink->value = d;
	newLink->next = s->firstLink;
	s->firstLink = newLink;
}
