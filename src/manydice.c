#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(int argc, char*argv[])
{
    int dice, roll;
    int sides;
    int status;

    srand((unsigned int) time(0)); // randomize seed
    printf("Enter the number of sides per die, 0 to stop.\n");
    while (scanf("%d", &sides) == 1 && sides > 0 )
    {
	printf("How many dice?\n");
	if ((status = scanf("%d", &dice)) != 1)
	{
	    if (status == EOF)
		break;		//exit loop
	    else
	    {
		printf("You should have entered an integer.");
		printf(" Let's begin again. \n");
		while (getchar() != '\n')
		    continue;		    //dispose of bad input
		printf("How many sides? Enter 0 to stop.\n");
		continue;
	    }
	}
	roll = roll_n_dice(dice, sides);
	printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
	printf("How many sides? Enter 0 to stop.\n");
    }
    printf("The rollem() function was called %d time.\n", roll_count);
    printf("Good Fortune to YOu.\n");

    return 0;
}
