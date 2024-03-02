/*Name: Kira Cibak
Description: This program allows a user to enter an encrypted message and decrpyts the message for them. It uses two functions: one to read and store the user input and one to decrpyt the message.*/

#include <stdio.h>

void decrypt(char *input, char *output); //(6-7)Function declarations
void read_line(char *c, int n); 

#define mx 1000 //Macro definition for maximum input length

int main (void)
{

    char in[1000], out[1000]; //Initializes the input an output arrays to the maximum size

    printf("Enter message: "); //(16-17)Message prompts user to enter input and function call allows user to enter input until \n is inserted
    read_line(in, 1000);
    
    decrypt(in, out); //Function call

    printf("Output: "); //(21-22)Prints output message and displays decrypted message for user
    printf("%s\n", out);

    return 0; //Ends main program
}


void decrypt(char *input, char *output) //Function prototype; returns nothing, takes in two char arrays
{

    char *p, *q; //(31-33)Initializes two char pointers, one pointing to input and the other to output
    p=input;
    q=output;

    int count=1; //(35-42)Initializes a count variable that allows the encrypted message letters to be read once; while loop continues until null char is discovered; while this condition is true, the given element of the output array is set to the current value of input, output and count are incremented by one, and input is incremented by count
    while(*p != '\0')
    {

        *q=*p;
        q++;
        p+=count;
        count++;

    }

    *q='\0'; //Sets the last element of the output array to the null char
}


void read_line(char *c, int n) //Function prototype; returns nothing, takes in a char array and an int
{

    int d; //(50-51)Declares two ints and initializes one to zero
    int j=0;

    while((d=getchar()) != '\n') //(53-61)While the user input is anything but \n, the user can continue to enter characters; as long as the count variable is less than the length of the max length of the input and the while loop condition is true, the user input is stored in the character array
    {

        if(j<n)
        {

            *c=d;
            c++;
            j++;

        }
    }

    *c='\0'; //Sets the last element of the input array to the null char
}