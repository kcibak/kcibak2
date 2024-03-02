/*Name: Kira Cibak
Description: The program allows a user to "insert coins" and select a candy selection. 
If there is an insufficient amount of cents or an invalid candy selection, the program displays an error
message and terminates. An infinite for loop and switch statement are used to complete the task.
This program would be helpful for a vending machine or something similar.*/
#define hk 15 //Initializes the price of a Hershey's kisses
#define rpb 25 //Initializes the price of a Reese's Peanut Butter Cup
#define sn 50 //Initializes the price of a Snickers
#include <stdio.h> //This includes the standard input-output header file
int main(void){ //This represents that the function takes no argument
    int coins, out, total=0; //Initializes the variables coins, out, and total as integers and sets total to zero
    for(; ;){ //This begins the infinite for loop, which continues to prompt the user to input until they enter zero
        printf("Insert coins: "); //Text that prompts user to enter their input
        scanf("%d",&coins); //Enables user input
        if(coins!=0){ //Depicts the case where the input is not zero
            total=total+coins; //Sets the total amount of cents to the sum of the current value and the newly input value
        }
        if(coins==0) //Depicts the case where the input is zero
            break; //Terminates and exits loop, as this means the user is finished "inserting" coins
    }
    int choice; //Initializes the variable choice, which is the user's candy selection
    printf("1 - Hershey's kisses (15 cents), 2 - Reese's Peanut Butter Cups (25 cents), 3 - Snickers (50 cents)\n"); //Prints a summary of the possible candy selections
    printf("Enter your choice:"); //Text that prompts user to enter their input
    scanf("%d",&choice); //Enables user input
    switch (choice){ //This traverse the different possible outcomes depending on the choice of candy
        case 1: //The Hershey's kisses choice
            if(total<hk){ //This depicts the scenario where the total of coins available is less than the price of the given candy selection
            printf("Insufficient amount. %d cents returned", total); //Prints error message
            }
            if(total>=hk){ //This depicts the scenario where the total of coins available is greater than or the same as the price of the given selection
                out=total-hk; //This sets the output variable to the difference between the total coins available and the price of the given selection
                printf("Your change is %d cents",out); //This prints the user's change with a short title
            }
            break; //Terminates and exits loop
        case 2: //The Reese's Peanut Butter Cup choice
            if(total<rpb){ //This depicts the scenario where the total of coins available is less than the price of the given candy selection
                printf("Insufficient amount. %d cents returned", total); //Prints error message
            }
            if(total>=rpb){ //This depicts the scenario where the total of coins available is greater than or the same as the price of the given selection
                out=total-rpb; //This sets the output variable to the difference between the total coins available and the price of the given selection
                printf("Your change is %d cents",out); //This prints the user's change with a short title
            }
            break; //Terminates and exits loop
        case 3: //The Snickers choice
            if(total<sn){ //This depicts the scenario where the total of coins available is less than the price of the given candy selection
                printf("Insufficient amount, %d cents returned", total); //Prints error message
            }
            if(total>=sn){ //This depicts the scenario where the total of coins available is greater than or the same as the price of the given selection
                out=total-sn; //This sets the output variable to the difference between the total coins available and the price of the given selection
                printf("Your change is %d cents",out); //This prints the user's change with a short title
            }
            break; //Terminates and exits loop
        default: //This is the case where the user input invalid (i.e., not 1, 2, or 3)
            printf("Invalid selection, %d cents returned", total); //Prints error message
            break; //Terminates and exits loop
   }
   return 0; //Terminates program
}