#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define MAX 10
#define BUFLEN 6
#define NUMTHREAD 2

void *consumer(void *id);
void *producer(void *id);

char buffer[BUFLEN];
char source[BUFLEN];
int pCount = 0;
int cCount = 0;
int buflen;

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0, 1};

int main()
{
    int i;
    pthread_t thread[NUMTHREAD];
    strcpy(source, "abcdef");
    buflen = strlen(source);

    pthread_mutex_init(&count_mutex, NULL);
    pthread_cond_init(&nonEmpty, NULL);
    pthread_cond_init(&full, NULL);

    pthread_create(&thread[0], NULL, &producer, (void *)&thread_id[0]);
    pthread_create(&thread[1], NULL, &consumer, (void *)&thread_id[1]);

    for (i=0; i<NUMTHREAD; i++){
        pthread_join(thread[i], NULL);
    }

    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&nonEmpty);
    pthread_cond_destroy(&full);
    return 0;
}

void *producer(void *id)
{
    for (int i=0; i<MAX; i++){
        pthread_mutex_lock(&count_mutex);
        while ((pCount - cCount) == BUFLEN){
            pthread_cond_wait(&full, &count_mutex);
        }
        char p = source[pCount%buflen];
        buffer[pCount%buflen] = p;
        printf("%d produced %c by Thread %d\n",i,p, *((int*)id));
        pCount++;
        pthread_mutex_unlock(&count_mutex);
        pthread_cond_signal(&nonEmpty);
    }
    pthread_exit(NULL);
}

void *consumer(void *id)
{
    for (int j=0; j<MAX; j++){
        pthread_mutex_lock(&count_mutex);
        while (cCount == pCount){
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }
        char c = buffer[cCount%buflen];
        printf("%d consumed %c by Thread %d\n",j,c, *((int*)id));
        cCount++;
        pthread_mutex_unlock(&count_mutex);
        pthread_cond_signal(&full);
    }
    pthread_exit(NULL);
}