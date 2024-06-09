/*Name: Kira Cibak
Description: This program reads an input file and writes the data to a struct array. Then, the struct array is traversed to search for an item entered by the user to see what inventory of that item there is. The function then writes the items that match the user input to an output file.*/


#include <stdio.h> // Include standard input/output
#include <string.h> // Include string library
#include <ctype.h> // Include character-type functions


struct supply{ // Define struct supply
    char name[100]; // Define character array for name
    char color[100]; // Define character array for color
    int quantity; // Define integer variable for quantity
};

int search(struct supply list[], int n, struct supply result[], char* search_name); // (14-15) Function declarations
int read_line(char str[], int n);

int main() {
    
    int num_supplies=0; // Initialize integer variable for number of supplies

    char item[100]; // Initialize character array for item
    printf("Enter supply: ");
    read_line(item, 100); // Allows user to input supply

    FILE* input=input=fopen("supply.csv", "r"); // Open the file supplies.csv for reading
    FILE* output=output=fopen("result.csv", "w"); // Open the file result.csv for writing

    struct supply in[200]; // Initialize array of struct supply

    while (!feof(input)) { // Read the input file until the end of the file
        fscanf(input, "%[^,], %[^,], %d\n", in[num_supplies].name, in[num_supplies].color, &in[num_supplies].quantity); // Read the input file and store the data in the struct array
        in[num_supplies].name[strlen(in[num_supplies].name)] = '\0'; // (32-33) Appends null character to end of name and color
        in[num_supplies].color[strlen(in[num_supplies].color)] = '\0';
        num_supplies++; // Increment number of supplies
    }

    struct supply out[200]; // Initialize array of struct supply

    int j=search(in, num_supplies, out, item); // Call search function, save return value to integer variable j (length of out file)

    int first_element=1; // Initialize integer variable for first element in order to format output file

    for (int i = 0; i < j; i++) { // Traverses the array of struct supply and writes the data to the output file
        if (!first_element) { // (44-48) If not the first element, print a newline (formatting purposes)
            fprintf(output, "\n");
        } else {
            first_element = 0;
        }
        fprintf(output, "%s, %s, %d", out[i].name, out[i].color, out[i].quantity);
    }

    fclose(input); // (52-53) Close the input and output files
    fclose(output);

    return 0; // Terminate main function
}



int search(struct supply list[], int n, struct supply result[], char* search_name){ // Define search function
    int count = 0;
    
    for(int i = 0; i < n; i++){ // Traverse the array of struct supply (input file)
        if(strcmp(list[i].name, search_name) == 0){ // Compare the name of the item to the user input
            if (count < 200) { // Ensure not to exceed the bounds of result array
                result[count] = list[i]; // Store the data in the result array
                count++;
            }
        }
    }
    return count; // Return the number of items that match the user input
}

int read_line(char str[], int n) // Define read_line function
{
    int ch, i = 0;

    while(isspace(ch = getchar())); // Skip leading white space if any

    str[i++] = ch;

    while ((ch = getchar()) != '\n') { // Read characters until newline
        if (i < n)
            str[i++] = ch; // Store the characters in the character array
    }
    str[i] = '\0'; // Append null character to end of string
    return i; // Return the length of the string
}