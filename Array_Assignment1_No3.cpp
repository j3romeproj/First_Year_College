/*	Create a C program that will search for an integer value from a list of n integer values 
	and count the number of occurrences of that number. 

	Example: 
      	List contains :     5    6    5   9    5   3   2   7   5  6 
      	Number to be searched is 5 

	Output:   There are 4 occurrences of the number 5 */

#include<stdio.h>
#include<conio.h>

int x[10];
int i, n, Num;
char ans = 'Y';

main()
{   // Input integer value
	for (i = 0; i < 10; i++){
		printf(" Enter an integer value: ");
		scanf("%d", &x[i]);
	}

    // Display all integer value
	printf("\n List contains: ");
	for (i = 0; i < 10; i++)
        printf("%3d", x[i]);

    // Control statement to know if the user wants to search a number again
    while (ans == 'Y' || ans == 'y'){
        printf("\n\n Enter the number you want to search: "); // Input a number to be searched
            scanf( "%d", &n);

        // Display the number that you want to search
        printf("\n\t Number to be searched is %d\n", n);

        // Statement used to check if the number is in the list
        Num = 0;
        for (i = 0; i < 10; i++){
            if (x[i] == n)
                Num++;
        }

        // Display how many occurence the number appear in the list
        printf("\n\t There are %d occurence/s of the number %d\n", Num, n);

        // Input yes or no (Y/N) if you want to search again
        printf("\n Would you like to search again? (Y/N): ");
            scanf("\n");
            scanf("%c", &ans);
    }

getch();
return 0;
}
