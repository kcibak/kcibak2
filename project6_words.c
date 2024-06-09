#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_square(char* word);

int main() {
    
    char fn[100]; // Initialize string variable for user input
    printf("Enter file name: ");
    scanf("%s", fn); // Allows user to input file name

    FILE* input=fopen(fn, "r"); // Open the file depicted by user input for reading
    
    if(input==NULL) { //Depicts case where file is not found
        printf("Error: file not found\n");
        return 1; // Abnormal termination
    }

    FILE* output=fopen("output.txt", "w"); // Open the file output.txt for writing

    char word[100]; // Initialize string variable for word
    int first_word = 1; // Flag to check if the first word has been printed

    while(fscanf(input, "%99s", word) == 1) { // Traverses input file while scanning for words

        if(is_square(word)) { // Depicts case where word is string repeated twice
            
            if (!first_word) { // Ensures that a newline is printed before each word except the first word
                fprintf(output, "\n");
            } 

            else {
                first_word = 0; // Set the flag to false after printing the first word
            }

            fprintf(output, "%s", word); // Print the word to the output file
        }
    }

    fclose(input); // (37-38) Close the input file and output file (if open)
    fclose(output);

    return 0; // End program
}


int is_square(char *word) { // Function definition

    int len = strlen(word); // Initialize variable for length of word (not including null terminator)
    
    if (len % 2 == 0 && len > 1) { // Check if the length of the word is even and greater than 1
        int half_len = len / 2;
        

        for (int i = 0; i < half_len; i++) { 

            if (word[i] != word[i + half_len]) { // Check if the first half of the word does not match the second half
                return 0; // Not repeated
            }
        }

        return 1; // If the first half matches the second half, return 1
    }
    
    return 0; // Not repeated
}
