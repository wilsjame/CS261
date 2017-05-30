/*
 * CS 261 Assignment 5
 * Name: James Wilson
 * Date: 29 May 2017
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXED
    Task *newTask = malloc(sizeof(Task));
    assert(newTask != 0);
    strcpy(newTask->name, name);
    newTask->priority = priority;

    return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
    // FIXED
    Task *l = (Task*) left;
    Task *r = (Task*) right;

    int return_me = 0;

    if(l->priority < r->priority)
    {
	    return_me = -1;
    }
    else if(l->priority > r->priority)
    {
	    return_me = 1;
    }

    //left priority == right priority
    return return_me;

}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
