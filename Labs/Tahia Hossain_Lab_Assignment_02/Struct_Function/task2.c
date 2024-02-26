#include <stdio.h>

int is_perfect(int num){
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0) 
            sum += i;
    }
    return sum == num;
}

void print_perfect_numbers(int start, int end) {
    printf("The Perfect numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) 
    {
        if (is_perfect(i))
            printf("%d\n", i);
    }
}

int main() {
    int start, end;

    printf("Starting number: ");
    scanf("%d", &start);

    printf("Ending number: ");
    scanf("%d", &end);

    print_perfect_numbers(start, end);

    return 0;
}