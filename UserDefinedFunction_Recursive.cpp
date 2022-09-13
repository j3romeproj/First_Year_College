/*      Create a recursive function to get the value of xy. Therefore, 25 = 32. */

#include <stdio.h>
#include <conio.h>

int rai(int base, int exponent) // Receiver of passed value from Fuction Call
{
    if (exp == 0) // to Check if expnent is = 0
        return 1;  // if the expnent is 0, the result is always 1
    else
        return (base * rai(base, exp - 1));	// recursive solution
}
main()
{   int base, exp; // Declaration of variable

    printf("Enter for the base: "); // Input for the base integer
    scanf("%d", &base);

    printf("Enter for the expnent: "); // Input for the expnent integer
    scanf("%d", &exp);

    printf("\n\t%d raid to %d is equal to %d", base, exp, rai(base, exp)); //displays the returned value and Function Call

getch();
return 0;
}
