#include <stdio.h>
#include <conio.h>

// called function
void sorts(int *int1, int *int2, int *int3) // void data type and pointer variable
{
   int x;  // declaration of variable that holds all variables

   if (*int1 > *int2){  // compare the int1 and int2 and switching the following statements
		x = *int1;
		*int1 = *int2;
		*int2 = x;
   }

   if (*int1 > *int3){ // compare the int1 and int3 and switching the following statements
		x = *int1;
		*int1 =*int3;
		*int3 = x;
   }

   if (*int2 > *int3){ // compare int2 and int3 and switching the following statements
		x = *int2;
		*int2 = *int3;
		*int3 = x;
   }
}

main()
{
   int int1, int2, int3; // declared variables

    // Input the 3 integers
   printf("\nEnter the integer: ");
   scanf("%d", &int1);
   printf("Enter the integer: ");
   scanf("%d", &int2);
   printf("Enter the integer: ");
   scanf("%d", &int3);

   sorts(&int1, &int2, &int3); //function call

   printf("\nSorted integer: %3d %3d %3d\n", int1, int2, int3);  // output

getch();
return 0;
}
