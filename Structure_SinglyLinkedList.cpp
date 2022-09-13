/*      Create a menu driven program for singly linked list.  Menu option are as follows: 

        MAIN MENU 

        A. Enter Linked List values 
        B. Compute and Display sum of values 
        C. Display highest value 
        D. Display lowest value 
        E. Display odd numbers 
        F. Display even numbers 
        G. Exit 

        Note:   Terminate input when the number zero is entered for option A. 
                Options B – F cannot be chosen unless linked list was created first. */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<limits.h>
#include<conio.h>

// Linked List of Structures
struct node{// Structure Definition
    int x;
    struct node *next;
};

struct node *head, *curr, *tail; // Structure Declaration
// User-Defined Function
void singly();          // Function Prototyping for Singly Linked List
void listsum();         // Function Prototyping to Compute and Display the sum of the values
void high(), low();     // Function Prototyping for the Highest and lowest Values
void odd(), even();     // Function Prototyping for the Odd and Even Values

int i, sum, temp, temp1;
int min = INT_MAX, max = INT_MIN; // Declaration of the integers
char ch[2];                                 // Declaration of the Characters

main(){
    head=curr=tail=NULL;
    // While Loop to keep asking or showing the main menu of the program until the user entered G. Exit
    while(1){// Displaying the Main Manu of the Program
        printf("\n\t\t MAIN MENU");
        printf("\n\n\tA. Enter Linked List");
        printf("\n\tB. Compute and Display sum of values");
        printf("\n\tC. Display highest Value");
        printf("\n\tD. Display lowest Value");
        printf("\n\tE. Display Odd Numbers");
        printf("\n\tF. Display Even Numbers");
        printf("\n\tG. Exit");

        // Inputting the Chosen Menu in main menu
        printf("\n\n\tChoose a Letter in MENU: ");
            scanf("\n");
            gets(ch);
        // Conditional Statement
        if(stricmp(ch, "A") == 0 ){
            singly();                                    // Function Call for Singly Linked List
        }else if((stricmp(ch, "G") == 0)){
            printf("\n\t\tThank you!");
            goto tapos;
        }else if(head == NULL){
            system("cls");
            printf("\n\tNo linked list entered.\n");
        }else if(stricmp(ch, "B") == 0){
            listsum();                                  // Function Call to Compute and Display the sum of the values
        }else if(stricmp(ch, "C") == 0){
            high();                                     // Function Call to determine the Highest value in the list
        }else if(stricmp(ch, "D") == 0){
            low();                                      // Function Call to determine the lowest value in the list
        }else if(stricmp(ch, "E") == 0){
            odd();                                      // Function Call to determine all Odd values in the list
        }else if(stricmp(ch, "F") == 0){
            even();                                     // Function Call to determine all Even values in the list
        }
    }
tapos:
    getch();
    return 0;
}

void singly(){// Function Singly
    system("cls");
    curr = (struct node *) malloc(sizeof(struct node));
    printf("\n\tEntering Linked List");
    printf("\n\n\tEnter an integer: ");
    scanf("%d", &curr->x);

    while(curr->x != 0){
        if(head == NULL){
            head = curr;
            head->next = NULL;
            tail = curr;
        } else {
            tail->next = curr;
            tail = curr;
        }

        curr = (struct node *) malloc(sizeof(struct node));
        printf("\tEnter an integer: ");
        scanf("%d", &curr->x);
        curr->next = NULL;
    }
    system("cls");
    printf("\n\tLinked List Inputted\n");
}

void listsum(){// Function listsum
    system("cls");
    sum = 0;
    curr = head;
    printf("\n\tThe linked list values are:\n\n\t");
    while(curr != NULL){
        printf("%4d", curr->x);
        sum += curr->x;
        curr = curr->next;
    }
    printf("\n\n\tThe sum of the linked list is: %d\n", sum);
}

void high(){// Function high
    system("cls");
    curr = head;
    printf("\n\tThe linked list values are:\n\n\t");
    while(curr != NULL){
        printf("%4d", curr->x);
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL) {
        if (curr->x > max) {
            max = curr -> x;
        }
        curr = curr -> next;
    }
    printf("\n\n\tThe highest value in the linked list is: %d\n", max);
}

void low(){// Function low
    system("cls");
    curr = head;
    printf(" \n\tThe linked list values are: \n\n\t");
    while(curr != NULL){
        printf("%4d", curr->x);
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL) {
        if (curr -> x < min) {
            min = curr -> x;
        }
        curr = curr -> next;
    }
    printf("\n\n\tThe lowest value in the linked list is:  %d\n", min);
}


void odd(){// Function odd
    system("cls");
    curr = head;
    printf(" \n\tThe linked list values are: \n\n\t");
    while(curr != NULL){
        printf("%4d", curr->x);
        curr = curr->next;
    }
    curr = head;
    printf(" \n\n\tThe odd values in the linked list are: \n\n\t");
    while(curr != NULL){
        if(curr->x%2 != 0){
            printf("%4d", curr->x);
            temp1 = 1;
        }
        curr = curr->next;
    }
    if(temp1 != 1)
        printf("\tNo Odd Number in the List");
    printf("\n");
}

void even(){// Function even
    system("cls");
    curr = head;
    printf(" \n\tThe linked list values are: \n\n\t");
    while(curr != NULL){
        printf("%4d", curr->x);
        curr = curr->next;
    }
    curr = head;
    printf(" \n\n\tThe even values in the linked list are: \n\n\t");
    while(curr != NULL){
        if(curr->x%2 == 0){
            printf("%4d", curr->x);
            temp = 1;
        }
        curr = curr->next;
    }
    if(temp != 1)
        printf("\tNo Even Number in the List");
    printf("\n");
}
