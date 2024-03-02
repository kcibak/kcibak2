//Name: Kira Cibak
/*Description: This program allows a user to choose a party package for a certain amount of hours and guests. 
There are amount restrictions on the number of hours and the amount of guests attending the party. There is a price ceiling on
the amount that can be charged for a party. The output is given as a dollar amount. Switch statements, if statements, and nested versions of both
are used to traverse the packages, amount of guests, and hours.*/
#include <stdio.h>
#define p1_c1 150 //Cost for package 1 for 1st hour
#define p2_c1 180 //Cost for package 2 for 1st hour
#define p3_c1 200 //Cost for package 3 for 1st hour
#define p1_c2 100 //Cost for package 1 after 1st hour
#define p2_c2 120 //Cost for package 2 after 1st hour
#define p3_c2 150 //Cost for package 3 after 1st hour
#define p1gmin 5 //Minimum number of guests for package 1
#define p1gmax 20 //Maximum number of guests for package 1
#define p2gmin 8 //Minimum number of guests for package 2
#define p2gmax 30 //Maximum number of guests for package 2
#define p3gmin 10 //Minimum number of guests for package 3
#define p3gmax 40 //Maximum number of guests for package 3
#define p1_food 25 //Cost of food per person for package 1
#define p2_food 22 //Cost of food per person for package 2
#define p3_food 20 //Cost of food per person for package 3
#define mxp1 595 //Max cost for package 1
#define mxp2 850 //Max cost for package 2
#define mxp3 1050 //Max cost for package 3

int main(void){
    printf("Please select from three packages: 1, 2, and 3\n"); //Prompts user to choose from the package options
    printf("Enter package selection:"); //Prompts user to enter their choice of package
    int pack; //Initializes package variable. This will be set to the user's input
    scanf("%d",&pack); //Enables user input and stores their entry to pack
    if(pack<1 || pack>3){ //Statement selecting the scenarios in which the package selection would be invalid
        printf("Invalid selection."); //Outputs error message
        return 0;} //Ends program
    printf("Enter hours:"); //Prompts user to enter the number of hours
    int hours; //Initializes hours variable. This will be set to the user's input
    scanf("%d",&hours); //Enables user input and stores their entry to hours
    if(hours<1 || hours>4){ //Statement selection the scenarios in which the number of hours would be invalid
        printf("Invalid hours."); //Outputs error message
        return 0; //Ends program
    }
    printf("Enter the number of guests:"); //Prompts user to enter the number of guests attending
    int guests; //Initializes the guests variable. This will be set to the user's input
    scanf("%d",&guests); //Enables user input and stores their entry to guests
       switch (pack){ //Statement to traverse the different packages; this loop is used to output the error messages for if the number of guests is invalid
        case 1: if(guests<p1gmin || guests>p1gmax){ //Start of case 1 and the if statement that ensures the number of guests is ivaild for the package
                    printf("Invalid number of guests."); //Outputs error message
                    return 0; //Ends program
                    break; //Terminates and exits loop
        }
        case 2: if(guests<p2gmin || guests>p2gmax){ //Start of case 2 and the if statement that ensures the number of guests is ivaild for the package
                    printf("Invalid number of guests."); //Outputs error message
                    return 0; //Ends program
                    break; //Terminates and exits loop
        }
        case 3: if(guests<p3gmin || guests>p3gmax){ //Start of case 3 and the if statement that ensures the number of guests is ivaild for the package
                    printf(" Invalid number of guests.");
                    return 0; //Ends program
                    break; //Terminates and exits loop
        }
        default: break; //Terminates and exits loop if the case is not a valid case
    }
    int totalCost; //Initializes the final output variable
    switch (pack){ //Traverses the different packages; this loop is used to determine the total cost given that all the user inputs are valid
        case 1: if(hours==1){ //Start of case 1 (package 1) and the if statement depicts the number of hours
                    totalCost=p1_c1+(guests*p1_food); //Sets the total cost output for an hour long party of the given package
                    }
                else{ //This statement depicts the cases where the number of hours is greater than one but less than the max number of hours given the package
                    totalCost=p1_c1+guests*p1_food+(p1_c2*(hours-1)); //Sets the total cost output for a package 1 party greater than 1 hour long
                    }
                break; //Terminates and exits loop
                
        case 2: if(hours==1){ //Start of case 2 (package 2) and the if statement depicts the number of hours
                    totalCost=p2_c1+(guests*p2_food); //Sets the total cost output for an hour long party of the given package
                    }
                else{ //This statement depicts the cases where the number of hours is greater than one but less than the max number of hours given the package number
                    totalCost=p2_c1+(guests*p2_food)+(p2_c2*(hours-1)); //Sets the total cost output for a package 2 party greater than 1 hour long
                    }
                break; //Terminates and exits loop
        case 3: if(hours==1){ //Start of case 3 (package 3) and the if statement depicts the number of hours
                    totalCost=p3_c1+guests*p3_food; //Sets the total cost output for an hour long party of the given package
                    }
                else{ //This statement depicts the cases where the number of hours is greater than one but less than the max number of hours given the package number
                    totalCost=p3_c1+guests*p3_food+(p3_c2*(hours-1)); //Sets the total cost output for a package 3 party greater than 1 hour long
                    }
                break; //Terminates and exits loop
        default: printf("Invalid selection."); //Outputs the error message for the case in which the package selection is invalid
        break; //Terminates and exits loop
    }
    if(pack==1){ //This depicts the case in which the user input for selection is 1
        if(totalCost>mxp1){ //This depicts the case where the total cost given the valid user inputs is greater than the maximum cost allowed for package 1
            totalCost=mxp1; //This sets the total cost output to the maximum cost allowed for package 1
        }
    }
    if(pack==2){ //This depicts the case in which the user input for selection is 2
      if(totalCost>mxp2){ //This depicts the case where the total cost given the valid user inputs is greater than the maximum cost allowed for package 2
          totalCost=mxp2; //This sets the total cost output to the maximum cost allowed for package 2
        }
    }
    if(pack==3){ //This depicts the case in which the user input for selection is 3
        if(totalCost>mxp3){ //This depicts the case where the total cost given the valid user inputs is greater than the maximum cost allowed for package 3
            totalCost=mxp3; //This sets the total cost output to the maximum cost allowed for package 3
        }
    }
    printf("Charge($):%d",totalCost); //This prints the final output, which is the total cost, along with its title statement
    return 0; //Ends program
}
