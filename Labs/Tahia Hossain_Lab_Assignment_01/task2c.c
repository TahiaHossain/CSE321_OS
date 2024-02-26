#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool uppercase(const char *password){
    while (*password) 
    {
        if (isupper(*password))
            return true;
        password++;
    }
    return false;
}

bool lowercase(const char *password){
    while (*password) 
    {
        if (islower(*password))
            return true;
        password++;
    }
    return false;
}

bool digit(const char *password){
    while (*password) 
    {
        if (isdigit(*password))
            return true;
        password++;
    }
    return false;
}

bool special_char(const char *password) {
    while (*password) 
    {
        if (*password == '_' || *password == '$' || *password == '#' || *password == '@')
            return true;
        password++;
    }
    return false;
}

int main(){
    char password[30];
    printf("Enter a password: ");
    scanf("%s", password);

    bool valid = true;

    if (!lowercase(password)) 
    {
        printf("Lowercase character missing\n");
        valid = false;
    }
    if (!uppercase(password)) 
    {
        printf("Uppercase character missing\n");
        valid = false;
    }
    if (!digit(password)) 
    {
        printf("Digit missing\n");
        valid = false;
    }
    if (!special_char(password)) 
    {
        printf("Special character missing\n");
        valid = false;
    }
    if (valid) 
    {
        printf("OK\n");
    }

    return 0;
}
