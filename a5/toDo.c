/*
 * CS 261 Assignment 5
 * Name: James Wilson 
 * Date: 29 May 2017
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXED
    char *fileName = malloc(sizeof(char) * 256);
    char *taskInfo = malloc(sizeof(char) * 256);
    int priority;

    //determine operation based of user command
    switch(command)
    {

	    // load the list from a file
	    case 'l':
		    printf("Enter the name of the file to load: ");
		    fgets(fileName, 100, stdin);

		    //check for null terminator
		    if(fileName[strlen(fileName) - 1] == '\n')
		    {
			    fileName[strlen(fileName) - 1] = 0;
		    }

		    FILE *read = fopen(fileName, "r");
		    listLoad(list, read);
		    printf("List loaded successfully.\n\n");
		    fclose(read);
		    break;

            // save the list to a file
	    case 's':
	            printf("Enter the name of the file to load: ");
		    fgets(fileName, 100, stdin);

	            //check for null terminator
		    if(fileName[strlen(fileName) - 1] == '\n')
		    {
			    fileName[strlen(fileName) - 1] = 0;
		    }

	            FILE *write = fopen(fileName, "w");
		    listSave(list, write);
		    printf("List saved successfully.\n\n");
		    fclose(write);
		    break;
               
             // add a new task to the list
             case 'a':
		    printf("Enter task: ");
		    fgets(taskInfo, 100, stdin);

		    //check for null terminator
		    if(taskInfo[strlen(fileName) - 1] == '\n')
		    {
			    taskInfo[strlen(fileName) - 1] = 0;
		    }

		    printf("Enter task priority number (0-999): ");
		    scanf("%d", &priority);
		    while(getchar() != '\n'); //handle memory leaks
		    Task *task = taskNew(priority, taskInfo);
		    dyHeapAdd(list, task, taskCompare);
		    printf("%s added successfully.\n\n", taskInfo); 
		    break;

             // get the first task from the list
	     case 'g':

		    if(dySize(list) != 0)
		    {
			    printf("First task toDo: %s.\n\n", ((struct Task *)dyHeapGetMin(list))->name); 
		    }
		    else
		    {
			    printf("List empty.\n\n");
		    }

		    break;

             // remove the first task from the list
	     case 'r':

		    if(dySize(list) == 0)
		    {
			    printf("List empty. \n\n");
		    }
		    else
		    {
			    struct Task* temp = (struct Task*)dyHeapGetMin(list);
			    printf("First task '%s' removed.\n\n", temp->name);
			    dyHeapRemoveMin(list, taskCompare);
			    taskDelete(temp);
		    }

	     // print the list
             case 'p':

		    if(dySize(list) == 0)
		    {
			    printf("List empty. \n\n");
		    }
		    else
		    {
			    listPrint(list);
		    }

		    break;

             // exit program
             case 'e':
		    printf("Exiting..\n\n");

		    break;

    }

    //free dynamic memory
    free(taskInfo);
    free(fileName);

}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */

    dyDelete(list);
    return 0;
}
