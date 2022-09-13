/*	Create a C program that will input integer values in a 5 x 5 array, then do the following: 

	a. Get the sum of the rows and place it in a one-dimensional array. 
	b. Get the sum of the columns and place it in a one-dimensional array. 
	c. Determine if all the row sum are equal and display the message “Row sums are equal”.  Otherwise, display “Row sums are not equal’.   
	d. Determine if all the column sum are equal and display the message “Column sums are equal”.  
	   Otherwise, display “Column sums are not equal’.   */

#include<stdio.h>
#include<conio.h>
// Program
int x[5][5];
int sumrow[5];
int sumcol[5];
int i,j;

main( )
{   // Inputting integer values in 5x5 array
    for (i=0; i<5; i++)
        for (j=0; j<5; j++){
            printf(" Enter an integer value for x[%d][%d]: ",i,j);
            scanf("%d", &x[i][j]);
        }
    // Displaying the array values
    printf("\n The array values are\n\n");
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            printf("%5d", x[i][j]);
        }
        printf("\n");
    }
    // A. Get the sum of the rows and place it in a one-dimensional array.
    // Displaying the sum of the rows
    printf("\n");
    printf(" Sum of rows in an array:\n\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            sumrow[i] += x[i][j]; // statement used to summarized the value each row
        }
        printf("\t %d \n", sumrow[i]); // print/display the sum value  each row
    }
    // B. Get the sum of the columns and place it in a one-dimensional array.
    // Displaying the sum of the columns
    printf("\n");
    printf(" Sum of columns in an array:\n\n");
    for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
            sumcol[i] += x[j][i]; // statement used to summarized the value each column
        }
        printf("\t %d \n", sumcol[i]); // print/display the sum value  each column
    }
    // C. Determine if all the row sum are equal and display the message “Row sums are equal”.  Otherwise, display “Row sums are not equal’.
    // Checking if the sum of the rows are equal or not equal
    for(i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            // conditional statement to identify if the rows are equal or not equal
            if(sumrow[i] != sumrow[j])
                break;
            if(i != j)
                printf("\n Rows sums are not equal\n");
            else
                printf("\n Rows sums are equal\n");
    // D. Determine if all the column sum are equal and display the message “Column sums are equal”.  Otherwise, display “Column sums are not equal’.
    // Checking if the sum of the columns are equal or not equal
    for(i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            // conditional statement to identify if the columns are equal or not equal
            if(sumcol[i] != sumcol[j])
                break;
            if(i != j)
                printf("\n Column sums are not equal\n");
            else
                printf("\n Column sums are equal\n");

getch();
return 0;
}
