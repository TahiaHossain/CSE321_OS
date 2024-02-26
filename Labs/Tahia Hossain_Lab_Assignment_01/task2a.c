#include <stdio.h>

int addition(int x, int y){
    return x+y;
}

int subtraction(int x, int y){
    return x-y;
}

int multiplication(int x, int y){
    return x*y;
}

int main(){
    int n1, n2, result;
    char operator;

    // taking inputs
    printf("Enter the First Number: ");
    scanf("%d", &n1);

    printf("Enter the Second Number: ");
    scanf("%d", &n2);

    printf("Enter the Operator (+, - or *): ");
    scanf(" %c", &operator);

    // Implementation
    if (n1 > n2)
    {
        if (operator == '-') 
        {
            result = subtraction(n1, n2);
            printf("Result: %d\n", result);
        } 
        else 
        {
            printf("Invalid operator for subtraction. Please use '-'\n");
        }
    } 
    else if (n1 < n2) 
    {
        if (operator == '+')
        {
            result = addition(n1, n2);
            printf("Result: %d\n", result);
        } 
        else
        {
            printf("Invalid operator for addition. Please use '+'\n");
        }
    } 
    else if (n1 == n2)
    {
        if (operator == '*') 
        {
            result = multiplication(n1, n2);
            printf("Result: %d\n", result);
        } 
        else 
        {
            printf("Invalid operator for multiplication. Please use '*'\n");
        }
    }

    return 0;

}