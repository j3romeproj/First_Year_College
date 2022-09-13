#include <stdio.h>
#include <conio.h>
// declaring integers
int int1, int2;

int gcd(int int1, int int2){                                    // Function Call
	do // Formula to determine the GCD of two integers          // Function Definition
    {   if (int1 > int2)
            int1 -= int2;
		else if (int1 == 0){
            break;
        }else
            int2 -= int1;
    }while (int2 != 0);

return int1; // returning value to the main
}

main()
{
    do
    {   printf ("\n\tEnter two integers (ex. 9 81): "); // Input
        scanf ("%d %d", &int1, &int2);

        printf("\n\tThe GCD of %d and %d is %d\n\n", int1, int2, gcd(int1,int2)); // Output and Function Call

    }while (int1 != 0 && int2 != 0); // It is to determine if the inpputed value have 0 that may end the program
        printf ("\n\t\tEnd of Program\n\n");

getch();
return 0;
}
