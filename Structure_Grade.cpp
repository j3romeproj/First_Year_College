/*      Create a program that will compute for the grade average of a student in 3 quizzes.  
        Moreover, compute the average of 5 students per quiz and grade average.   

        Note: 
        Grade value may range from 000.00 to 100.00  */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

// In this program I used For Loop, Structure, and Function Statements
struct record                               // Structure Definition
{
    char num[10];
    char name[15];
    float quiz[3], ave;
};

struct record stu_rec[5];                   // Structure Declaration
int i, j;                                   // Declaring Integers for loop
float q1ave, q2ave, q3ave, finave, ch;      // Declaring Floats used for quiz average
void restrict();                            // Function Prototyping

main()
{   // Referencing Structure Elements
    for(i = 0; i < 5; i++){
        printf("\n\tEnter Student Name: ");
            scanf("\n");
            gets(stu_rec[i].name);
        printf("\tEnter Student Number: ");
            scanf("\n");
            gets(stu_rec[i].num);

        printf("\n");
        for(j = 0; j < 3; j++){
            printf("\tEnter Grade for Quiz#%d: ", j + 1);
                scanf("%f", &stu_rec[i].quiz[j]);
                restrict();
        }
        // Formula for Average
        stu_rec[i].ave = (stu_rec[i].quiz[0] + stu_rec[i].quiz[1] + stu_rec[i].quiz[2]) / 3;
        q1ave += (stu_rec[i].quiz[0]) / 5;
        q2ave += (stu_rec[i].quiz[1]) / 5;
        q3ave += (stu_rec[i].quiz[2]) / 5;
        finave = (q1ave + q2ave + q3ave) / 3;
        system("cls");
    }
    // Output of the Program
    printf("\n\t\t\t\tPOLYTECHNIC UNIVERSITY OF THE PHILIPPINES\n\t\t\t\t\t   QUEZON CITY BRANCH");
    printf("\n\n\t\t\t\t\t\tBSIT 1-2\n");

    printf("\n\tSTUDENT NUMBER\t\t   STUDENT NAME\t\tQUIZ#1\tQUIZ#2\tQUIZ#3\t\tGRADE AVERAGE\n");
    for(i = 0; i < 5; i++)
        printf("\n\t    %10s\t\t%15s\t\t%.2f\t%.2f\t%.2f\t\t        %.2f", stu_rec[i].num, stu_rec[i].name, stu_rec[i].quiz[0], stu_rec[i].quiz[1], stu_rec[i].quiz[2], stu_rec[i].ave);

    printf("\n\n\tAverage:\t\t\t\t\t%.2f\t%.2f\t%.2f\t\t        %.2f", q1ave, q2ave, q3ave, finave);

getch();
return 0;
}
// Function Restrict and its Definition
void restrict()
{
    while ((stu_rec[i].quiz[j] < 000.00 || stu_rec[i].quiz[j] > 100.00))
    {
        while(( ch = getchar()) !='\n')
            continue;
        printf("\n\t===================================================");
        printf("\n\tERROR!! Please enter between 00.00 and 100.00 ONLY!");
        printf("\n\t===================================================");
        printf("\n\n\tEnter Grade for Quiz#%d: ", j + 1);
        scanf("%f", &stu_rec[i].quiz[j]);
    }
}
