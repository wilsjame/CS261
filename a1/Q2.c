/* CS261- Assignment 1 - Q.2*/
/* Name: James Wilson
 * Date: 12 April 2017
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a = *a * 2;
    
    /*Set b to half its original value*/
	*b = *b / 2;
    
    /*Assign a+b to c*/
	c = *a + *b;
    
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5, y = 6, z = 7, foo_return;
    
    /*Print the values of x, y and z*/
	printf("x, y, and z before call to foo()\nx = %i\ny = %i\nz = %i\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
	foo_return = foo(&x, &y, z);

    /*Print the value returned by foo*/
	printf("Return value of foo() = %i\n", foo_return);
    
    /*Print the values of x, y and z again*/
	printf("x, y, and z after call to foo()\nx = %i\ny = %i\nz = %i\n", x, y, z);
 
    /*Is the return value different than the value of z?  Why?*/
    return 0;
}
    
/* The return value is different than the value of z because z is passed to foo() by value instead of reference. Therefore, z's value is manipulated locally and returned but the actual value of z is not changed.*/
    
