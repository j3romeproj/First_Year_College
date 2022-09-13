/*      Create a password program which will allow for 3 tries only. 
        If password entered is successful, then display the message “Welcome to PUP Quezon City!”. 
        Otherwise, display the message “Intruder Alert!” Password entered must be hidden using the “*” */

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
// this password program used User-Defined Function
int i, x, n, length, temp;
char pass[]={};

bool results(char y[])                                                  // Function Call
{   char defpass[] = "PUPQCLANG"; //Default password                    // Function Definition

        if(strcmp(defpass, y) != 0){ // identifying if its not equal to the default pass
            printf("\n\tIncorrect Password! Please Try Again!\n\n"); // output if its not equal
            return false; // returning false value to the main
        }else{
            printf("\n\tPassword is correct!\n"); // output if the if statement is false and it means its equal
            return true; // returning true value to the main
        }
    return 0;
}

main()
{
    for(x = 0; x < 3; x++){ // loop to have only 3 tries
        printf("\n\t\t   Attemp# %d\n", x+1);
        printf("\tPlease enter your password: "); // Input
        for(i=0;i<19;i++)
        {
            Input:
            temp = getch(); // instead of scanf, we are using getch to cover the password

            if (temp == '\010') // it is to identify/read the backspace and edit previous value
                {
                    pass[i-1] = '\0';
                    i--;
                    printf("\b");
                    goto Input;
                }

            if (temp == '\r') // for enter key
                {
                    break;
                }

            pass[i] = temp;
            temp = '*';
            printf("%c", temp);
        }

        if(results(pass)){ // Function Call
            printf("\n\tWelcome to PUP Quezon City!\n"); // Output if they detected the password is matched
            n = 0; // just to keep n to 0 so that intruder alert will not trigger
            break;
        }else
            n = 1; // trigger if all of the entered value is wrong
    }
    if(n == 1) // if statement to out put the trigger warning
        printf("\t\tIntruder Alert!\n\n"); // output if all entered password is wrong

getch ();
return 0;
}
