#include <pthread.h>
#include <stdio.h>
void *doWork(void *ptr)
{
    int *target = (int*) ptr;
    for (int i = 0; i < 100000; i++) {
        (*target)++;
    }
    return NULL;
}
int main(int argc, char **argv)
{
    pthread_t thread1, thread2;
    int toIncrement = 0;
    pthread_create(&thread1, NULL, *doWork, (void *) &toIncrement);
    pthread_create(&thread2, NULL, *doWork, (void *) &toIncrement);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Sum: %d\n", toIncrement);
    return 0;
}