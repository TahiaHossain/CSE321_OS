#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_Palindrome(const char *string) {
    const char *start = string; // Pointer to the beginning of the string
    const char *end = string + strlen(string) - 1; // Pointer to the end of the string

    while (start < end) 
    {
        if (*start != *end) 
        {
            return false; 
        }
        start++;
        end--;
    }

    return true; 
}

int main(){
    char user_input[256];
    printf("Enter a string: ");
    scanf("%s", user_input);

    if (check_Palindrome(user_input)) 
        printf("Palindrome\n");
    else 
        printf("Not Palindrome\n");

    return 0;
}