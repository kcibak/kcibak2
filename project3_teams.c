/*Name: Kira Cibak
Description: This program is designed for a teacher who wants to sort students onto teams based on their point level. The user enters the number of students and 
the point levels of each student. There are point ranges for each of the three teams. The program outputs the student number along with the team they should be 
assigned to based on their level of points.*/


#include <stdio.h> //This includes the standard input-output header file
#include <ctype.h> //This includes useful C functions

#define beg 25 //Macro definition for the beginner team point level
#define hon 70 //Macro definition for the honor team point level
#define exc 125 //Macro definition for the excellence team point level

int main(void){ //This represents that the function takes no argument

    int numS; //Initializes the number of students variable
    int i; //Initializes the variable that will hold user input
    int bc=0,hc=0,ec=0; //Initializes the 3 count variables for each team

    printf("Enter number of students: "); //Prompts user to enter the number of students
    scanf("%d",&numS); //Allows the user to enter input and stores it into the number of students variable

    int s[numS-1]; //Initializes a variable size array to the length of one less than the number of students.
    int b[numS], h[numS], ex[numS]; //Initializes 3 variable size arrays to the length of number of students 

    printf("Enter points for each student: "); //Prints message that prompts user to enter input
    for(int p=0;p<numS;p++){  //Traverses the student array
        scanf("%d",&i); //Allows the user to enter input and stores the int in the variable i
        s[p]=i; //Sets the array element decided by the for loop variable to the current iteration's user input
    }
    
    for(int k=0;k<(numS);k++){ //Traverses the student array
        if(s[k]<=beg){ //Depicts the case where the current student's point level is less than or equal to the beginner point level
            b[bc]=k+1; //Sets the given index of the beginner team array to one more than the for loop count variable. This depicts that the student is placed in the beginner team
            bc++; //Increments the count for number of beginner students by one
        }

        if(s[k]==hon){ //Depicts the case where the current student's point level is equal to the honor point level
            h[hc]=k+1; //Sets the given index of the honor team array to one more than the for loop count variable. This depicts that the student is placed in the honor team
            hc++; //Increments the count for number of honor students by one
        }

        if(s[k]>=exc){ //Depicts the case where the current student's point level is greater than or equal to the excellence point level
            ex[ec]=k+1; //Sets the given index of the excellence team array to one more than the for loop count variable. This depicts that the student is placed in the excellence team
            ec++; //Increments the count for number of excellence students by one
        }

        if(s[k]>beg && s[k]<hon){ //Depicts the case where the current student's point level is greater than the beginner point level and less than the honor point level
                if((s[k]-beg)<(hon-s[k])){ //Depicts the case where the current student's point level is closer to the beginner point level than the honor point level
                    b[bc]=k+1; //Sets the given index of the beginner team array to one more than the for loop count variable. This depicts that the student is placed in the beginner team
                    bc++; //Increments the count for number of beginner students by one
                }
                else{ //Depicts the case where the current student's point level is closer to the honor point level than the beginner point level
                    h[hc]=k+1; //Sets the given index of the honor team array to one more than the for loop count variable. This depicts that the student is placed in the honor team
                    hc++; //Increments the count for number of honor students by one
                }
        }

        if(s[k]>hon && s[k]<exc){ //Depicts the case where the current student's point level is greater than the honor point level and less than the excellence point level
                if((s[k]-hon)<(exc-s[k])){ //Depicts the case where the current student's point level is closer to the honor point level than the excellence point level
                    h[hc]=k+1; //Sets the given index of the honor team array to one more than the for loop count variable. This depicts that the student is placed in the honor team
                    hc++; //Increments the count for number of honor students by one
                }
                else{ //Depicts the case where the current student's point level is closer to the excellence point level than the honor point level
                    ex[ec]=k+1; //Sets the given index of the excellence team array to one more than the for loop count variable. This depicts that the student is placed in the excellence team
                    ec++; //Increments the count for number of excellence students by one
                }
        }
    }

    printf("Beginner team: student "); //Prints a message for user
    for(int a=0;a<(bc);a++){ //Traverses the beginner team array
        printf("%d ",b[a]); //Ouputs the student number depicting that they are on the beginner team
    }
    printf("\n"); //Prints newline

    printf("Honor team: student "); //Prints a message for user
    for(int q=0;q<(hc);q++){ //Traverses the honor team array
        printf("%d ",h[q]); //Ouputs the student number depicting that they are on the honor team
    }
    printf("\n"); //Prints newline

    printf("Excellence team: student "); //Prints a message for user
    for(int d=0;d<(ec);d++){ //Traverses the excellence team array
        printf("%d ",ex[d]); //Ouputs the student number depicting that they are on the excellence team
    }
    printf("\n"); //Prints newline
    
    return 0; //Ends program
}