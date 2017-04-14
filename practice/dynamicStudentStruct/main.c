#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	int id;
	char name[40];
};

void printStudent(struct student s)
{
	printf("Student name is %s\n", s.name);
	printf("Student id is %d\n\n", s.id);
}

void initStudent(int id, char *name, struct student *s)
{
	s->id = id;
	strcpy(s->name, name); /* string function from string.h */
}

int main (int argc, const char * argv[]) {
	
	/* hard coded. Possible user input at runtime */
	int numStudents = 3;

	struct student *myStudents = malloc(numStudents * sizeof(struct student));
	
	/* assert that malloc is successfull  ... assert(myStudents != 0 */

	/* myStudents[0,1,2] chunks of memory representing student structs.
	 * myStudents[0,1,2] dereferences the pointer, passes a copy of struct.
	 * &myStudents[0,1,2] passes address which is what we want. */
	initStudent(25, "Joe",  &myStudents[0]);
	initStudent(65, "Mary", &myStudents[1]);
	initStudent(36, "Kate", &myStudents[2]);
	
	/* using the array index operator dereferences myStudents poiner 
	 * and passes struct by value, no need to change */
	printStudent(myStudents[0]);
	printStudent(myStudents[1]);
	printStudent(myStudents[2]);
		
	free(myStudents);
}
