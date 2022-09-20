#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	struct node *prev;								// Singly linked list != prev
	int x;										// Prev|x|Next
	struct node *next;
} *head, *curr, *tail, *ptr, *temp, *in;						// NULL|head|next ! prev|curr|next ! prev|tail|NULL

int choice, tag;									// Declarations of variables
void create(), display(), printing(), reverse();// Function declarations
void sorting(), ascending(), descending(), insertnode();
void deletenode(), searchnode();

main()											// Main function
{menu: // printing menu
	while (1){
		printf("\n\t\tMAIN MENU\n");						// Printing
		printf("\t1. Create Doubly Linked List\n");
		printf("\t2. Display a Doubly Linked List\n");
		printf("\t   21. Normal Order\n");
		printf("\t   22. Reverse Order\n");
		printf("\t3. Sort a Doubly Linked List\n");
		printf("\t   31. Ascending\n");
		printf("\t   32. Descending\n");
		printf("\t4. Insert a Node\n");
		printf("\t5. Delete a Node\n");
		printf("\t6. Search a number in the list\n");
		printf("\t7. Exit\n");

		printf("\n\tEnter choice: ");						// Getting the user's choice
            scanf("%d", &choice);							// data to be stored at choice. 

        if(choice > 1 && choice != 7 && tag == 0){					// If the user did not input 1 or 7 the program will loop until the user input 1 or 7
            system("cls");
            printf("\n\tPlease Enter a Doubly Linked List first!");
            printf("\n\tPress any key to continue ....\n");
            getch();
            goto menu;									// going to menu
        }

		switch(choice){								// Switch case statement using the choice
			case 1: create(); break;																		// Creating doubly linked list
			case 2: display(); break;																		// Display
			case 21: system("cls"); printf("\n\tNormal Order: "); printing(); break;				// Printing in normal order
			case 22: system("cls"); printf("\n\tReverse Order: "); reverse(); break;				// Printing in reverse order
			case 3: sorting(); break;																// Sorting
			case 31: system("cls"); printf("\n\tAscending Order: "); ascending(); printing(); break;		// Printing in ascending 
			case 32: system("cls"); printf("\n\tDescending Order: "); descending(); printing(); break;		// Printing in descending 
			case 4: insertnode(); break;																	// Inserting node
			case 5: deletenode(); break;																	// Delete node
			case 6: searchnode(); break;																	// Search node
			case 7: goto tapos;																				// End program
			default: system("cls"); break;																	// Clear screen
		}
	}

tapos:										// End program
    printf("\n\t\tThank you!!");
    getch();
    return 0;
}

void create()									// Function for creating doubly linked list
{   system("cls");
    tag = 1;
	head = curr = tail = NULL; 			
	curr = (struct node *)malloc(sizeof(struct node));
	printf("\n\tEnter Doubly Linked List: ");
	scanf("%d", &curr->x);							// Getting the value for the data inside the nodes/x
	
	while(curr->x != 0){							// If the user entered 0 the getting of data will be terminated
		if(head==NULL)
		{
			head=curr;						// Head = curr
			head->prev=NULL;					// NULL | HEAD | ??
			head->next=NULL;					// NULL | HEAD | NULL	// IF 0 
			tail=curr;						// PREV | TAIL | NULL
		}
		else
		{
			tail->next=curr;					//      | Curr | curr
			curr->prev=tail;					// Tail | curr |		// IF > 0
			curr->next=NULL;					// 	| Curr | NULL
			tail=curr;						// 
		}
		curr = (struct node *)malloc(sizeof(struct node));		// allocations for node
		printf("\tEnter Doubly Linked List: ");				// Getting Data
		scanf("%d", &curr->x);
	}
system("cls");
}

void display()				// Printing
{   system("cls");
    printf("\n\t Doubly Linked List: "); printing();
    printf("\n\t===================================================");
    printf("\n\t\tChoose a Mode!");
    printf("\n\tEnter:");
    printf("\n\t\t21 = Normal Mode");
    printf("\n\t\t22 = Reverse Mode");
    printf("\n\t===================================================\n");
}

void printing()										// Printing of the list
{   curr = head;

	while(curr != NULL)
	{
		printf("%3d", curr->x);							// Will print until the end is reached
		curr = curr->next;							// Traversing forward
	}
	printf("\n\n");
}

void reverse()										// Printing in reverse
{   curr = tail;									// Will go to end node

	while(curr != NULL)								// Will print until 
	{		
		printf("%3d", curr->x);							// Will print until the end is reached
		curr = curr->prev;							// Traversing backwards
	}
	printf("\n\n");
}

void sorting()										// Sorting function
{   system("cls");
    struct node *i, *j;									// Declared new pointers
    int temp;										// Temporary storage for sorting
    for(i = head; i->next != NULL; i = i->next){					// I = Head node; I = next!= NULL; I = I ->next;
        for(j = i->next; j != NULL; j = j->next){					// J = I -> next; J != NULL; = J = J->
            if(i->x > j->x){								// x > j? || 2 > 1?
                temp = j->x;								// 0 = 1 |temp storage = 2nd node
                j->x = i->x;								// 1 = 2 | 2nd node = 1st node
                i->x = temp;								// 2 = 1 | 1st node = temp storage
            }
        }
    }
    printf("\n\tSorted Linked list: "); printing();
    printf("\n\t===================================================");
    printf("\n\t\tChoose a Mode!");
    printf("\n\tEnter:");
    printf("\n\t\t31 = Ascending Mode");	
    printf("\n\t\t32 = Descending Mode");
    printf("\n\t===================================================\n");
}

void ascending()									// 1 | 2 | 3 | 4 
{   struct node *i, *j;									// Declared new pointers
    int temp;										// Decalred temp storage
    for(i = head; i->next != NULL; i = i->next){					// 1st node | Condition for 1st node and 2nd node comparison
        for(j = i->next; j != NULL; j = j->next){					// 2nd node
            if(i->x > j->x){								// Is 1st node is greater than 2nd node? 2 > 1?
                temp = j->x;								// temp storage = 2nd node | 0 = 1
                j->x = i->x;								// 2nd node = 1st node 	   | 1 = 2
                i->x = temp;								// 1st node = temp storage | 2 = 1 (temp storage)
            }
        }
    }
}

void descending()									// 4 | 3 | 2 | 1
{   struct node *i, *j;									// Declared new pointers
    int temp;										// Decalred temp storage
    for(i = head; i->next != NULL; i = i->next){					// 1st node | Condition for 1st node and 2nd node comparison
        for(j = i->next; j != NULL; j = j->next){					// 2nd node
            if(i->x < j->x){								// Is 1st node is less than 2nd node? 1 > 2?
                temp = j->x;								// temp storage = 2nd node | 0 = 2
                j->x = i->x;								// 2nd node = 1st node     | 2 = 1 
                i->x = temp;								// 1st node = temp storage | 1 = 2 (temp storage)
            }
        }
    }
}

void insertnode()
{
    curr = (struct node*)malloc(sizeof(struct node));					// Memory allocation for nodes
    printf("\n\tEnter node value: ");							// Printing
    scanf("%d", &curr->x);								// Getting the value of to be inserted node
    curr->next = NULL;									// 		|curr | NULL
    curr->prev = NULL;									// NULL |curr | 

    temp = head;									// temp = head
    struct node *temp1;									// creating new pointer for temp1
    while(temp->x < curr->x){								// While the temp->x is greater than curr->x
        temp1 = temp;									// 
        temp = temp->next;
    }
    curr->prev = temp1;
    curr->next = temp;
    temp1->next = curr;
    temp->prev = curr;

    system("cls");
    printf("\n\tThe doubly linked list after the insertion: ");
    printing();
}

void deletenode()
{   system("cls");
    int del, i;										// Declared new variable for del and i
    printf("\n\tDoubly Linked List: "); printing();d
    printf("\n\t\t\t   Delete a node!");
    printf("\n\t===================================================");
    printf("\n\tEnter a node: ");
        scanf("%d", &del);								// Getting the value for deletion
    system("cls");		

    temp = head;									// Temp = head 
    node* prev = NULL;									// NULL | temp |

    if(temp != NULL && temp->x == del){							// If the list is not empty and the data in nodes is equal to input del value
        head = temp->next;								// head = temp->next
        delete temp;									// deleting temp storage
        return;	
    }else{						
        while(temp != NULL && temp->x != del)	{					// If the list is not empty and not equal to input del value 
            prev = temp;								// prev = temp 
            temp = temp->next;								// temp will go to next node
        }
        if(temp == NULL)								// if the temp reached the end
            return;

        prev->next = temp->next;

        delete temp;
    }
    printf("\n\tNew Doubly List: "); printing();
}

void searchnode()
{
    int item, i, flag;									// Declared variables for item, i and flag
    char ans;										// Declared character variable for ans
    do{
        system("cls");
        printf("\n\t\t\t   Search a node!");
        printf("\n\t===================================================");
        printf("\n\tEnter a node: ");
            scanf("%d", &item);								// asked the user for input that user wants to search.
        ptr = head;									// ptr = head

        while(ptr != NULL){								// while the ptr is not 0 
            while(ptr->x == item){							// Is the item is equal to data in node
                printf("\n\t%d is in the list. It is in the node number/s %d\n", item, i+1); // Printing the searched node and it's number
                flag = 1; 
                break;
            }
            i++;									// i++ to increase the number for printing the nodes
            ptr = ptr->next; 								// going to next node
        }	
        if(flag == 0)									// if flag is 0 
            printf("\n\t%d is not in the list\n", item); 
        flag = 0;
        i = 0;
        printf("\n\t===================================================");
        printf("\n\tDo you want to search another number? ");
            scanf("%s", &ans);	// get another input
    }
    while(ans == 'Y' || ans == 'y'); // if Y then loop

    system("cls");
}
