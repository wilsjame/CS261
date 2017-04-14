/*********************************************************************
** Author: James G Wilson
** Date: 4/8/2017
** Description: Assignment 0 CS 261
** Converts and prints inches to centimeters and vice-versa
** for 0, 20, ..., 300
*********************************************************************/
#include <stdio.h>

main()
{
	float inches, centimeters;
	int lower, upper, step;

	lower = 0;	/* lower limit of table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	/*convert and print inches to centimeters*/
	inches = lower;
	printf("Inches To Centimeters Table\n");
	while (inches <= upper) {
		centimeters = 2.54 * inches;
		printf("%3.0f %6.1f\n", inches, centimeters);
		inches = inches + step;
	}

	/*convert and print centimeters to inches*/
	centimeters = lower;
	printf("Centimeters To Inches Table\n");
	while (centimeters <= upper) {
		inches = centimeters / 2.54;
		printf("%3.0f %6.1f\n", centimeters, inches);
		centimeters = centimeters + step;
	}
}
