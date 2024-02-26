#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char filename[MAX_LENGTH];

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w"); 

    if (file == NULL) 
    {
        printf("Error creating/opening file: %s\n", filename);
        return 1;
    }

    char input[MAX_LENGTH];
    while (1) 
    {
        printf("Enter a string or '-l' to exit: ");
        scanf("%s", input);

        if (strcmp(input, "-l") == 0)
            break; 

        fprintf(file, "%s", input); // Write the input string to the file
    }

    fclose(file); // Close the file

    return 0;
}