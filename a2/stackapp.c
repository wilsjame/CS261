/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
 	returns 1 if balanced and 0 otherwise
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function *FIXED*/		
	char ch;
	struct DynArr *stack = newDynArr(10);

	/* parse string */
	do{

		ch = nextChar(s); 

		if(ch == '(' || ch == '{' || ch == '['){
			pushDynArr(stack, ch);
		}

		if(ch == ')' || ch == '}' || ch == ']'){

			if(isEmptyDynArr(stack)){
					deleteDynArr(stack);

					return 0; /* string is not balanced */

			}
			else{

			popDynArr(stack);
			}

		}

	}while(ch != '\0');

	
	if(isEmptyDynArr(stack)){

		deleteDynArr(stack);

		return 1; /* string is balanced */

	}
	else{

	deleteDynArr(stack);

	return 0; /* string is not balanced */

	}

}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}
