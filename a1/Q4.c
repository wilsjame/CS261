/* CS261- Assignment 1 - Q.4*/
/* Name: James Wilson
 * Date: 12 April 2017
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
	int in_index, out_index;
	struct student temp;

	for(out_index = 0; out_index < n - 1; out_index++){
		for(in_index = 0; in_index < n - 1; in_index++){
			if(students[in_index].score > students[in_index + 1].score){
				temp = students[in_index];
				students[in_index] = students[in_index + 1];
				students[in_index + 1] = temp;
			}
		}
	}

}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 5, stud_index;
    
    /*Allocate memory for n students using malloc.*/
	struct student *pstud = malloc(n * sizeof(struct student));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
	for(stud_index = 0; stud_index < n; stud_index++){
		pstud[stud_index].id = rand() % n + 1;
    		pstud[stud_index].score = rand() % 100;
	}

    /*Print the contents of the array of n pstuds.*/
	printf("Unsorted students\n");

	for(stud_index = 0; stud_index < n; stud_index++)
		printf("ID%2i Score%i\n", pstud[stud_index].id, pstud[stud_index].score);

    /*Pass this array along with n to the sort() function*/
	sort(pstud, n);
    
    /*Print the contents of the array of n students.*/
	printf("Sorted students\n");

    	for(stud_index = 0; stud_index < n; stud_index++)
		printf("ID%2i Score%i\n", pstud[stud_index].id, pstud[stud_index].score);

    return 0;
}
