/* 	An integer is considered a prime number if its only factors are 1 and itself. 
	Create a function that will determine if an input number is prime or not. 
	Input ends when a zero value is entered. */

#include <stdio.h>
#include <conio.h>

int num;

int prime (int num)                                                                 //Function Call
{   int ans = 0;  // initialization and declaration                                 //Function Definition
	int count = num/2;

    for (int i = 2; i <= count; i++){
        if (num % i == 0){ // check if the remainder is equal to 0 then proceed to another statement
            ans = 1;   //if the remainder is not equal to zero then ans = 1
            break;
        }
    }

	if (num == 1) // if number = 1 then ans = 1
        ans = 1;

return ans; // it will now return the value of ans to the function call
}

main()
{
	do
    {   printf("Enter an integer: ");  // Input
        scanf("%d",&num);
        // It will now filter the inputted integer
        if(num == 0) // If the integer is 0, it will now proceed to another statement
            printf("\n"); // Output
        else if(prime(num) == 0) // if the returned value from function call, it wil now proceed to another statement
            printf("The number %d is a prime number\n\n", num); // Output
        else if(prime(num) == 1 && num != 0) // if the return value from function call is 1 or not equal to 0, it will now proceed to another statement
            printf("The number %d is not a prime number\n\n", num); // Output

    }while(num != 0); // as long as there's no zero inputted value, the program will continue

getch();
return 0;
}
