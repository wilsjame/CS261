#include "linkedList.h"
#include "assert.h"
#include <stdlib.h>
#include <stdio.h>




/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *frontSentinel;
	struct DLink *backSentinel;
};


/* prototypes */
void _removeLink(struct linkedList *lst, struct DLink *l);


/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
   /* create the sentinels */
  }

/*
 createList
 param: none
 pre: none
 post: frontSentinel and backSentinel reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*freeLinkedList
 * param: lst the linkedList
 * pre: lst is not null
 * post: All data-bound links are freed
 */

void _freeLinkedList(struct linkedList *lst)
{
	struct DLink *cur = lst->frontSentinel->next;
	while(cur != lst->backSentinel)
	{
		_removeLink(lst,cur);
	}
}
/*
 * deleteList
 * param: lst the linkedList
 * pre: lst is not null
 * post: the memory used by frontSent, backSent, and lst is freed
 */

void deleteLinkedList(struct linkedList *lst)
{
	/* Fix me */ }
/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
   /* Fix me */ }


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{

	/* Fix me */ 
}

/*
	addBackList
	param: lst the linkedList
	pre: lst is not null
	post: lst is not empty
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
  /* Fix me */ 
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
   /* Fix me */ }

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	/* Fix me */ 
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* Fix me */ 
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   /* Fix me */ 
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
	/* Fix me */ 

}
/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
  /* Fix me */ 
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	/* Fix me */ 
}

/* Iterative implementation of contains() 
 Pre: lst is not null
 */

void addList(struct linkedList *lst, TYPE v)
{
	assert(lst != 0);
	addBackList(lst, v);
}

/* Iterative implementation of contains() 
 Pre: lst is not null
 pre: list is not empty
 */
int containsList (struct linkedList *lst, TYPE e) {
	/* Fix me */ 
}

/* Iterative implementation of remove() 
 Pre: lst is not null
 pre: lst is not empty
 */
void removeList (struct linkedList *lst, TYPE e) {
	/* Fix me */ 
}

/* Iterator Interface */
/*---------------------------------------------------------------------------------------------------*/

struct linkedListIter {
	struct DLink *cur;
	struct linkedList *lst;
};

/* Initialize an iterator */

void  initlinkedListIter (struct linkedList *lst, struct linkedListIter *itr) {
	itr->lst = lst;
	itr->cur = itr->lst->frontSentinel; /* set current to right before the first elements (design option)*/
}

/* create a new iterator struct and return it */

struct linkedListIter *createlinkedListIter(struct linkedList *lst){
	struct linkedListIter *newItr = malloc(sizeof(struct linkedListIter));
	assert(newItr != 0);
	initlinkedListIter(lst, newItr);
	return(newItr);
}

 /* Determines if there are more values in the collection and if so, returns true.  It also
  * sets up for the subsequent call to 'next' by making cur point to the next value in the collection.
  */
int hasNextlinkedListIter (struct linkedListIter *itr) {

	if(itr->cur->next != itr->lst-backSentinel){
		itr->cur = itr->cur->next;
		
		return(1);

	}
	else
	{
		
		return 0;

	}


}

/* returns the next value in the collection */
TYPE nextlinkedListIter (struct linkedListIter *itr) {

	return itr->cur->value; 

}

/* removes the last value returned by 'next'
 * Notice that we use a tmp to ensure that the following
 * calls to hasNext and next are correct after removal of the
 * current link.*/
void removelinkedListIter (struct linkedListIter *itr) {
	struct Dlink *temp = itr->cur;
	itr->cur = itr->cur->prev;
	_removeLink(itr->lst, temp);
}





///*Bag Wrapper Interface*/
//struct bag *createBag()
//{
//	struct bag *myBag = malloc(sizeof(struct bag));
//	myBag->lst = createLinkedList();
//	return myBag;
//}
//void addToBag(struct bag* b, TYPE val)
//{
//	addList(b->lst, val);
//}
//void removeFromBag(struct bag* b, TYPE val)
//{
//	removeList(b->lst, val);
//}
//int containsBag(struct bag* b, TYPE val)
//{
//	return(containsList(b->lst, val));
//}
//int isEmptyBag(struct bag* b)
//{
//	return(isEmptyList(b->lst));
//}
//
//void printBag(struct bag *b)
//{
//	_printList(b->lst);
//}
