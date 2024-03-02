/*Name: Kira Cibak
Description: This program allows a user to enter a message as a command line argument and tells the user whether their message is valid or not. All functionality takes place in the main function.*/

#include <stdio.h> //This includes the standard input-output header file
#include <ctype.h> //This includes useful C functions


int main(int argc, char *argv[])
{ 

    if(argc < 2) //(11-15)This depicts the case where there are not enough arguments; if the condition is met, the program prints an error message and terminates
    {
        printf("invalid number of arguments\n");
        return 0;
    }

    for (int i = 1; i < argc; i++) //(17-20)The first for loop traverses the arguments, the second traverses the characters of each argument; as long as i is less than the number of arguments and argv[i][j] is not the null char, the loops continue
    {

        for (int j = 0; argv[i][j] != '\0'; j++)
        {

            if((argv[i][j] == '?') || (argv[i][j] == '!') || islower(argv[i][j]) || isdigit(argv[i][j]) || isspace(argv[i][j]) || (argv[i][j] == '.')) //(23-26)This depicts the case where the message is valid and continues to the next iteration of the loop if the condition is met
            { 
                continue; 
            }

            else //(28-32)Depicts the case where the message is invalid, prints the invalid message, and terminates the program as soon as an invalid char is encountered
            { 
                printf("invalid"); 
                return 0;
            }
        }
    }

     printf("valid\n"); //So long as the else condition was not met, the message is valid and the message is printed

    return 0; //Terminates program
}