#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock; // type for pthread mutexes

void *doWork(void *ptr)
{
    int *target = (int*) ptr;
    pthread_mutex_lock(&lock); // blocks until we get the lock
    for (int i = 0; i < 100000; i++) {
        (*target)++;
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t thread1, thread2;
    int toIncrement = 0;
    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\n Mutex is kill\n"); 
        return 1; 
    } 
    pthread_create(&thread1, NULL, *doWork, (void *) &toIncrement); // TODO: Check these return 0 = sucess
    pthread_create(&thread2, NULL, *doWork, (void *) &toIncrement);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Sum: %d\n", toIncrement);
    return 0;
}