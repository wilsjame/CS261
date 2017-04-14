/* CS261- Assignment 1 - Q.3*/
/* Name: James Wilson
 * Date: 12 April 2017
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/     
	int out_index, in_index, temp;

	for(out_index = 0; out_index < n - 1; out_index++){
		for(in_index = 0; in_index < n - 1; in_index++){
			if(number[in_index] > number[in_index + 1]){
				temp = number[in_index];
				number[in_index] = number[in_index + 1];
				number[in_index + 1] = temp;
			}
		}
	}
	
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20, index;
    
    /*Allocate memory for an array of n integers using malloc.*/
	int *array = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/

	for(index = 0; index < n; index++)
		array[index] = rand();
    
    /*Print the contents of the array.*/
	printf("Unsorted array\n");

	for(index = 0; index < n; index++)
		printf("%i\n", array[index]);

    /*Pass this array along with n to the sort() function of part a.*/
	sort(array, n);
    
    /*Print the contents of the array.*/    
	printf("Sorted array\n");

	for(index = 0; index < n; index++)
		printf("%i\n", array[index]);
    
    return 0;
}
