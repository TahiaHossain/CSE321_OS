#include <stdio.h>
#include <pthread.h>
#include <string.h>

struct Item {
    int quantity;
    float unit_price;
};

struct ThreadArgs {
    char name[100];
    int ascii_sum;
};

int sumOfAscii(const char *name) {
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum;
}

void calculateSum(struct ThreadArgs *args) {
    int temp_sum = sumOfAscii(args->name);
    args->ascii_sum = temp_sum;
}

int main() {
    pthread_t threads[4];
    struct ThreadArgs thread_args[3];

    printf("Enter three user names:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%s", thread_args[i].name);
    }

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, (void *)calculateSum, &thread_args[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    if (thread_args[0].ascii_sum == thread_args[1].ascii_sum && 
            thread_args[0].ascii_sum == thread_args[2].ascii_sum) 
        printf("Youreka\n");
    else if (thread_args[0].ascii_sum == thread_args[1].ascii_sum || 
               thread_args[0].ascii_sum == thread_args[2].ascii_sum || 
               thread_args[1].ascii_sum == thread_args[2].ascii_sum) 
               
         printf("Miracle\n");

    else
        printf("Hasta la vista\n");

    return 0;
}