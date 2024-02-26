#include <stdio.h>
#include <stdlib.h>

void removeExtraSpaces(FILE *inputFile, FILE *outputFile) {
    char prevChar = ' ';
    char currentChar;

    while ((currentChar = fgetc(inputFile)) != EOF) // End Of File 
    {
        if (!(prevChar == ' ' && currentChar == ' '))
        {
            fputc(currentChar, outputFile);
        }
        prevChar = currentChar;
    } 
}

int main() {
    FILE *inputFile, *outputFile;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error opening output file\n");
        fclose(inputFile);
        return 1;
    }

    removeExtraSpaces(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Extra spaces removed and saved to output.txt\n");

    return 0;
}