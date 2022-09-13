#include<stdio.h>
#include<conio.h>

int x[5][5];
int i, j;

main()
{// Inputting integer values in 5x5 array
	for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++){
            printf(" Enter an integer value for x[%d][%d]: ", i, j);
            scanf("%d", &x[i][j]);
        }
	// Display the original x values
    printf("\n\n Original x Values:\n\n");
	for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%5d", x[i][j]);
        }
        printf("\n");
    }
	// Display the changed x values
	printf("\n\n Changed x Values:\n\n");
	for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            // Conditional statements to change all the inputted negative values into zero
            if (x[i][j] < 0){
                x[i][j] = 0;
            }
            printf("%5d", x[i][j]); // Display the original values and changed values
        }
        printf("\n");
    }

getch();
return 0;
}
