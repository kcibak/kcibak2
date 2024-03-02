/*Name: Kira Cibak
Description: This program allows a user to enter a number of students, point values for each student, and returns team assignments for each student.*/


#include <stdio.h> //This includes the standard input-output header file
#include <ctype.h> //This includes useful C functions

#define beg 25 //(9-14)Macro definitions for beginner, honors, and excellence team variables
#define hon 70 
#define exc 125 
#define b 1
#define h 2
#define e 3

void assign(int * points, int * team_assignment, int n); //Function declaration

int main(void){ //This represents that the function takes no argument

    int numS, i;  //Initializes the number of students and user input variable

    printf("Enter number of students: "); //(22-23)Prints message and allows user to enter input
    scanf("%d",&numS); 

    int teams[numS]; //(25-26)Initializes teams and points arrays to a length equal to the number of students
    int pts[numS]; 

    printf("Enter points for each student: "); //(28-33)Prints input message for user and sets each element of the points array to the user input
    for(int j=0; j<numS ;j++)
    {  
        scanf("%d",&i); 
        pts[j]=i; 
    }

    assign(pts, teams, numS); //Function call, assigns integers to the teams array

    printf("Beginner team: student "); //(37-62)Prints messages defining output for user; each for loop traverses the teams array and if the condition is met, prints one plus the current index, indicating the student number
    for(int a=0;a<numS;a++)
    { 
        if(teams[a]==b)

            printf("%d ",a+1); 
    }
    printf("\n"); //Prints newline

    printf("Honor team: student "); 
    for(int a1=0;a1<numS;a1++)
    { 
        if(teams[a1]==h)

            printf("%d ",a1+1); 
    }
    printf("\n"); 

    printf("Excellence team: student "); 
    for(int a2=0;a2<numS;a2++)
    { 
        if(teams[a2]==e)

            printf("%d ",a2+1); 
    }
    printf("\n"); 
    
    return 0; //Ends main function
}


void assign(int *points, int *team_assignment, int n) //Function definition; returns nothing and takes two int arrays and an int as arguments
{
    int *p, *q; //Initializes int pointers
    q=team_assignment; //q points to team_assignment

    for(p=points; p<points+n; p++) //(74-102)This for loop traverses the points array; the if statements depict the conditions required to be assigned to the given team. If the condition is met, the teams array for the given index is set to b, h, or e
    {
        if(*p<=beg)
            *q=b;

        if(*p==hon)
            *q=h;

        if(*p>=exc)
            *q=e; 

        if(*p>beg && *p<hon)
        { 
                if((*p-beg)<(hon-*p)) 
                    *q=b; 
                
                else
                    *q=h; 
        }

        if(*p>hon && *p<exc)
        { 
                if((*p-hon)<(exc-*p))
                    *q=h; 

                else 
                    *q=e; 
        }
        
        q++; //This causes q to point to the next element in the team_assignment array
    }
}
