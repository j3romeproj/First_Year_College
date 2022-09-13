/* Create a function that will pass a 3x3 array to the function EXCHANGE. The function should be able to exchange the row and column values. */

#include<stdio.h>
#include<conio.h>
// initializing variables
int a[3][3];
int i, j;

int arr(int a[3][3])                                            // Function Call
{   // Loop to display proper arrangement of inputted integers  // Function Definition
	printf("\n\tThe Original Arrangement\n\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("\t %3d", a[i][j]);
		}
		printf("\n");
	}
    // Loop to display changed arrangement of inputted integers
	printf("\n\tChanged\n\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("\t %3d", a[j][i]); // Just to swap the i and j to exchange the rows and column values
		}
		printf("\n");
	}
}

main()
{
	printf("\n");
    // Array Loop to input integers
	for(i=0; i<3; i++)
		for(j=0; j<3; j++){
			printf("\tEnter a number [%d][%d]: ", i,j);
				scanf("%d", &a[i][j]);
		}

    arr(a); // Function Call

getch();
return 0;
}
