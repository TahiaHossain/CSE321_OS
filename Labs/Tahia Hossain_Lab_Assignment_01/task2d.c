#include <stdio.h>
#include <string.h>

int isUpdatedEmail(const char *email) 
{
    const char *newDomain = "sheba.xyz";
    const char *oldDomain = "kaaj.com";
    
    // Get the position of the '@' symbol in the email
    char *atSymbolPos = strchr(email, '@');
    
    if (atSymbolPos != NULL && strcmp(atSymbolPos + 1, newDomain) == 0)
        return 1;
    else if (atSymbolPos != NULL && strcmp(atSymbolPos + 1, oldDomain) == 0)
        return 0;
    else
        return -1;
}

int main(){
    char email[100];
    int result;

    printf("Enter an email address: ");
    scanf("%s", email);

    result = isUpdatedEmail(email);

    if (result == 1)
        printf("Email address is okay\n");
    else if (result == 0)
        printf("Email address is outdated\n");
    else
        printf("Invalid email format or Unrecognized Domain. Please Try Again.\n");

    return 0;
}