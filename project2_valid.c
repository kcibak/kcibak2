/*Name: Kira Cibak
Description: This program allows the user to input characters. There are some restrictions on
which characters are allowed. The user presses enter to denote that they are done entering
their input. A while loop with nested if and else statements are used along with if/else statements.*/
#include <stdio.h> //This includes the standard input-output header file
#include <ctype.h> //This includes useful C functions
int main(void){ //This represents that the function takes no argument
    int c; //Initializes the character variable
    int isValid=0; //Initializes the integer that determines if the input is valid/invalid
    printf("Enter input: "); //Prompts the user to enter their input
    while((c=getchar())!='\n'){ //Allows the user to continue inputting characters until they press the enter key
        if((c=='?') || (c=='!') || islower(c) || isdigit(c) || isspace(c) || (c=='.')){ //Depicts the scenario where the input is valid
            continue; //Continues through the loop
        }
        if(isupper(c)){ //Depicts a specific scenario where the input is invalid
            isValid=1; //Sets the determining variable to 1
        }
        else{ //Depicts every other scenario where the input is invalid
            isValid=1; //Sets the determining variable to 1
        }
    }
    if(isValid==0){ //Depicts the scenario where the entire input is valid
        printf("valid"); //Outputs a message to the user
    }
    else{ //Depicts the scenario where at least one character in the input is invalid
        printf("invalid"); //Outputs a message to the user
    }
    return 0; //Ends program
}
