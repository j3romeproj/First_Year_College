/* 	A palindrome is a string that reads the same both forward and backward. 
	Create a program that takes a string as an argument 
	and returns the int value 1 if the string is a palindrome 
	and display the message “<input string> is a Palindrome” 
	and returns 0 otherwise and display the message “<input string> is Not a Palindrome” */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

bool palindrome(char word[])
{   int value;
	int mid = strlen(word) / 2; //In this statement we will identify the middle of the string
	int len = strlen(word); //string length of the string
    // loop so that we will know if it is palindrome or not
	for (int i = 0; i < mid; i++)
		if (word[i] != word[len - i -1])
            return value = 0; // if the if statement is true, it will return value = 0
	return value = 1; // if the if statement is false, it will return value = 1
}
char word[]={};

int main(void)
{// inputting a word that want to know if it is palindrome or not
	printf("\n\tEnter a word: ");
	scanf("%s", word);

    // if-else statement to display if the world is palindrome or not
	if (palindrome(word) == 1)
		printf("\n\t%s is a palindrome", word);
	else
		printf("\n\t%s is not a palindrome", word);

getch();
return 0;
}
