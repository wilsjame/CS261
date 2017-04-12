/* CS261- Assignment 1 - Q.1*/
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

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *pstud = malloc(10 * sizeof(struct student));
     
     /*return the pointer*/
	return pstud;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int stud_index;

	for(stud_index = 0; stud_index < 10; stud_index++){
		students[stud_index].id = rand() % 10 + 1; 
		students[stud_index].score = rand() % 100;
	}

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int stud_index;

	for(stud_index = 0; stud_index < 10; stud_index++){
		printf("ID%2i Score%i\n", students[stud_index].id, students[stud_index].score); 
	}
		
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int stud_index = 0, index_score, min, max, sum;

	min = max = students[stud_index].score; /*first score is min and max*/

	for(stud_index = 0; stud_index < 10; stud_index++){ 
		index_score = students[stud_index].score;

		if(index_score < min)
			min = index_score;

		if(index_score > max)
			max = index_score;

		sum += index_score;
	}

	printf("Minimum:\t%i\nMaximum:\t%i\nAverage:\t%d\n", min, max, sum / 10);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

	if(stud != NULL)
		free(stud);

}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
