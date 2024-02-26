#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_INTEGERS 5

void *printIntegers(void *arg) {
    int thread_num = *(int *)arg;
    int start_integer = (thread_num * NUM_INTEGERS) + 1;

    for (int i = 0; i < NUM_INTEGERS; i++) {
        printf("Thread %d prints %d\n", thread_num, start_integer + i);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_numbers[NUM_THREADS] = {0, 1, 2, 3, 4};

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, printIntegers, &thread_numbers[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}