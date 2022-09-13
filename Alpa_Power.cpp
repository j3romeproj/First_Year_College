#include <stdio.h>
#include <math.h> // it is to use the pow statement
#include <conio.h>

int num, i;
// function call
int power(int num) //function power with 1 parameter num
{   int result; // local variable result to hold the result
     result = pow(2, num);
      return result; // return the value of result to the calling function
}

main()
{// Inputting desired power to compute
    printf("\n\tEnter a power: ");
    scanf("%d", &num);

    printf("\n\t\tBase 2\n");
    printf("\tPower\t\t Result\n");
    //output loop to know show the result
    for(i = 0; i < 11; i++){
        printf("\t%d\t\t %d\n", num, power(num));
        num++; //keep incrementing to continue increasing the desired power
    }

return 0;
getch ();
}
