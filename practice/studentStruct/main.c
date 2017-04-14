#include <stdio.h>
#include <string.h>


struct student {
	int id;
	char name[40];
};

int c = 8; /* global variable*/



void printStudent(struct student s)
{
	int c = 10;
	printf("Name of student is %s\n", s.name);
	printf("Id of student is %d\n", s.id);
	printf("Local value of c = %d\n", c);
	
}


int main (int argc, const char * argv[]) {
	struct student joe;
	strcpy(joe.name, "Joseph");
	joe.id = 5;
	//printf("Name of student is %s\n", joe.name);
	//printf("Id of student is %d\n", joe.id);
	printStudent(joe);
	
	struct student mary;
	strcpy(mary.name,"Mary");
	mary.id = 6;
	//printf("Name of student is %s\n", mary.name);
	//printf("Id of student is %d\n", mary.id);
	printStudent(mary);
	
	
	printf("Value of c = %d\n",c);
	c = 9;
	printf("Value of c = %d\n",c);

	
    return 0;
}
