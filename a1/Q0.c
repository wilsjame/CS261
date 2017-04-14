/* CS261- Assignment 1 - Q. 0*/
/* Name: James Wilson
 * Date: 11 April 2017
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("Value of what iptr points to:\t%d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
	printf("Address pointed to by iptr:\t%p\n", iptr);
     
     /*Print the address of iptr itself*/
	printf("Address of iptr itself:\t%p\n", &iptr);
}

int main(){

    /*declare an integer x*/
	int x;

    /*print the address of x*/
	printf("Address of x:\t%p\n", &x);
    
    /*Call fooA() with the address of x*/
	fooA(&x);
    
    /*print the value of x*/
	printf("Value of x:\t%d\n", x);
    
    return 0;
}
