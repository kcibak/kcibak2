/*Name: Kira Cibak
Description: This program allows a user to enter an array length along with a sequence of integers. The function called in the main depicts whether the sequence entered by the user is arithmetic or not.*/

#include <stdio.h>
#include <ctype.h>

int is_arithmetic_sequence(int *sequence, int n); //Function declaration

int main (void) //The main function takes in no argument
{
    int length; //(11-13)Declares integer length and allows the user to enter input and store it in this length variable
    printf("Enter length of the sequence: ");
    scanf("%d", &length);

    int seq[length]; //(15-16)Declares an int array of user input length and a variable for the user input to be stored
    int c;

    printf("Enter numbers of the sequence: "); //(18-23)Prints a message prompting the user; the for loop traverses the sequence array and initializes the given index element to the user input
    for(int j=0; j<length ; j++)
    {  
        scanf("%d",&c); 
        seq[j]=c; 
    }

    int a=is_arithmetic_sequence(seq, length); //Function call, stored in int a

    if(a==1) //(27-31)This depicts the case where the sequence is arithmetic and prints 'yes' if the condition is met
    {
        printf("yes");
        printf("\n");
    }

    else //(33-37)This depicts the case where the sequence is not arithmetic and prints 'no' if the above condition is not met
    {
        printf("no");
        printf("\n");
    }

    return 0; //Ends program
}


int is_arithmetic_sequence(int *sequence, int n) //Function prototype; returns and integer and has an int array and an int as arguments
{
    int *p=sequence+1; //Declares and initializes an int pointer pointing to the 2nd element of the argument array

    int x= (*p) - (*sequence); //Declares and initializes an int holding the value of the difference between the second and first elements of the argument array

    for(; p<(sequence+n); p++) //Traverses the array by incrementing the pointer to the argument array
    {

        if((*p) - (*(p-1))!=x) //(61-64)Depicts the case where the sequence is not arithmetic and returns 0
        {
            return 0;
        }


    }
    return 1; //Returns 1 if the condition in the for loop is not met
}