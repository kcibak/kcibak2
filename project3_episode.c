/*Name: Kira Cibak
Description: This program is for a user who likes to watch episodes of a show season out of order and who only has
one episode left to watch in their current season. It allows the user to enter the number of episodes in the season 
and which episodes they have already watched (in any order). The program outputs the final episode that is yet to be watched.*/


#include <stdio.h> //This includes the standard input-output header file
#include <ctype.h> //This includes useful C functions
void s_sort(int t[], int q); //Sort array in ascending order (function declaration)
int find_l(int t[], int q); //Find largest element in array (function declaration)

int main(void){ //This represents that the function takes no argument

    int numE, mE; //Initializes the number of episodes variable and the missed episode variable
    int count=1; //Initializes and sets the count integer to 1
    int i; //Initializes the user input variable

    printf("Enter number of episodes: "); //Prints message that prompts user to enter input
    scanf("%d",&numE); //Allows user to input an integer and stores this input into the variable numE
    int eW[numE-1]; //This initializes a variable-sized array of episode numbers whose length is set to one less than the
                    //total episodes in the season

    printf("Enter episodes watched: "); //Prints message that prompts user to enter input
    for(int p=0;p<numE-1;p++){ //Accesses the elements of the episodes watched array
        scanf("%d",&i); //Allows the user to enter input and stores the int in the variable i
        eW[p]=i; //Sets the current element to the current user input
    }

    s_sort(eW,numE-1); //Sorts the array in ascending numerical order

    for(int j=0;j<(numE);j++){ //Traverses the elements of the sorted array
        if(eW[j]==count){ //Depicts the case where the episode has been watched
            count++; //Increments the count variable by one
        }
        else{ //Depicts the case where the episode hasn't been watched
            mE=count; //Sets the missed episode variable to the current value of count
            printf("Missing episode: %d\n",mE); //Prints a message and the value for the missed episode
            return 0; //Terminates program
        }
    }
    return 0; //Terminates program
}

void s_sort(int t[], int q){ //Initializes the function name, expression types, and return type (function definition)
    int l = 0, temp; //Initializes ints l and temp and sets l to zero
    if(q==1) return; //Depicts the case where the input array length is one and terminates the function
    l=find_l(t,q); //Calls the find largest index function and sets the index value to the variable l
    temp=t[q-1]; //Sets the temp variable to the last element in the input array
    t[q-1]=t[l]; //Sets the given element in the array to the value of the largest element
    t[l]=temp; //Switches the element that was in the last index to the index where the largest was initially
    s_sort(t,q-1); //Calls the function recursively to complete the sorting task
}

int find_l(int t[],int q){ //Initializes the function name, expression types, and return type (function definition)
    int w,dex=0; //Initializes the loop variable and the index variable as ints
    for(w=1;w<q;w++){ //Traverses the input array
        if(t[w]>t[dex]){ //Depicts the case where the next element is larger than the one before it
            dex=w; //Sets the index variable to the current count value 
        }
    }
    return dex; //Returns the integer of the index of the largest element
}
