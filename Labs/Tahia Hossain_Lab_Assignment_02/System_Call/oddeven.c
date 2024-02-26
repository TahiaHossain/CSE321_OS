#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    printf("Odd/Even Status:\n");
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        if (num % 2 == 0) {
            printf("%s is Even\n", argv[i]);
        } else {
            printf("%s is Odd\n", argv[i]);
        }
    }

    return 0;
}