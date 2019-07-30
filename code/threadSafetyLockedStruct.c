#include <pthread.h>
#include <stdio.h>

struct ThreadInfo
{
    int threadID;
    int *toIncrement;
    pthread_mutex_t *lock;
};

// typedef struct ThreadInfo ThreadInfo

void *doWork(void *ptr)
{
    struct ThreadInfo *info = (struct ThreadInfo*) ptr;
    pthread_mutex_lock(info->lock); // blocks until we get the lock
    printf("Thread %d executing!\n", info->threadID);
    for (int i = 0; i < 100000; i++) {
        (*(info->toIncrement))++;
    }
    pthread_mutex_unlock(info->lock);
    printf("Thread %d done & unlocked!\n", info->threadID);
    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t thread1, thread2;
    pthread_mutex_t lock; // Why don't we need to malloc this?
    int toIncrement = 0;
    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\n Mutex is kill\n"); 
        return 1; 
    }

    struct ThreadInfo thread1Info = {1, &toIncrement, &lock};
    pthread_create(&thread1, NULL, *doWork, (void *) &thread1Info);
    struct ThreadInfo thread2Info = {2, &toIncrement, &lock};
    pthread_create(&thread2, NULL, *doWork, (void *) &thread2Info);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Sum: %d\n", toIncrement);
    return 0;
}