/*Name: Kira Cibak
Description: This program creates a linked list and allows a user to add nodes, print the list, and deallocate memory (quit). In total, it uses 4 functions to maintain the database.*/

#include <stdio.h> // Include standard input/output
#include <stdlib.h> // Include standard library functions
#include <string.h> // Include string functions
#include <ctype.h> // Include character-type functions
#define EMAIL_LEN 100 // Maximum email length
#define NAME_LEN 30 // Maximum name length


struct volunteer{ // Creates volunteer node with 3 strings and an integer
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	int grade_level;
	struct volunteer *next;
};


struct volunteer *add_to_list(struct volunteer *list); // (21-25) Function declarations
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
int read_line(char str[], int n);

int main(void)
{
  char code;

  struct volunteer *volunteer_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': volunteer_list = add_to_list(volunteer_list);
                break;
      case 's': search_list(volunteer_list);
                break;
      case 'p': print_list(volunteer_list);
                break;
      case 'q': clear_list(volunteer_list);
		            return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}


struct volunteer *add_to_list(struct volunteer *list) { // This function allows a user to add a volunteer to the list


  char l[NAME_LEN + 1] = ""; // (64-66) Initialize last, first, and email members with an empty string
  char f[NAME_LEN + 1] = ""; 
  char e[EMAIL_LEN + 1] = "";
  int g; // Initialize grade-level variable

  printf("Enter last name: "); // (69-76) User input; calls read_line and scanf; saves input in last, first, email, and grade-level
  read_line(l,NAME_LEN+1);
  printf("Enter first name: ");
  read_line(f,NAME_LEN+1);
  printf("Enter email address: ");
  read_line(e,EMAIL_LEN+1);
  printf("Enter grade level: ");
  scanf("%d", &g);

  struct volunteer *new_volunteer=malloc(sizeof(struct volunteer)); // Allocates space for user input 
  if(new_volunteer==NULL){ // (79-82) Allocation test
    printf("malloc failed in add_to_list");
    return list;
  }

  strcpy(new_volunteer -> last, l); // (84-87) Stores user input in members of new volunteer node
  strcpy(new_volunteer -> first, f);
  strcpy(new_volunteer -> email, e);
  new_volunteer->grade_level = g;
  new_volunteer->next = NULL; // Sets next pointer to NULL

  if (list == NULL) { // If the list is empty, return pointer to new volunteer node
    return new_volunteer;
  }

  struct volunteer *current = list; // Condition for where list has preexisting data; sets current node to last element of list


  while(current -> next != NULL){ // Traverses list until the end of the list is reached; ensures that the user input does not match preceding data


    if((strcmp(current ->last, l)==0) && (strcmp(current ->first, f)==0) && (strcmp(current ->email, e)==0) && (current ->grade_level==g)){
      
      printf("volunteer already exists.\n");
      
      return list;
    }
    current=current -> next; // Moves to next node
  }
  current->next = new_volunteer; // Appends new volunteer node to end of list

  return list;
}


int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;

  str[i++] = ch;

  while ((ch = getchar()) != '\n') {

    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';

   return i;
}


void search_list(struct volunteer *list) // This function allows a user to search for a volunteer by grade level 
{

  int g; // Initialize grade-level variable

  int count=0; // Initialize count variable for condition where volunteer DNE

  printf("Enter grade level: "); // User input for grade level
  scanf("%d", &g);

  struct volunteer *current = list; // Sets current node to first element of list

  while(current != NULL){ // Traverses list until the end of the list is reached

    if(current -> grade_level == g){ // If the user input matches the grade level of a volunteer, print the volunteer's information

      printf("%-12s%-12s%-30s\n", current -> last, current -> first, current -> email);

      count++; // Increments count
    }

    current=current -> next; // Moves to next node
  }

  if(current==NULL && count == 0){ // If the user input does not match any grade levels, print "not found"

    printf("not found\n");
  }
}


void print_list(struct volunteer *list){ // This function prints the list of volunteers
  struct volunteer *current=list; // Sets current node to first element of list

  while(current != NULL){ // Traverses list until the end of the list is reached

    printf("%-12s%-12s%-30s%5d\n", current -> last, current -> first, current -> email, current -> grade_level);

    current=current -> next; // Moves to next node
  }
}


void clear_list(struct volunteer *list) // This function frees the memory allocated for the list
{
  struct volunteer *current;

  while(list != NULL){

    current=list;

    list=list -> next;

    if(current != NULL){
      free(current);
    }
  }
}