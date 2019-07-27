#include <pthread.h>
#include <stdio.h>
void *doWork(void *ptr)
{
    int type = *(int*) ptr;
    printf("Hello! I'm thread %d\n", type);
    return NULL;
}
int main(int argc, char **argv)
{
    pthread_t thread1, thread2; // Maybe malloc these
    pthread_create(&thread1, NULL, *doWork, (void *) &thr);
    pthread_create(&thread2, NULL, *doWork, (void *) &thr2);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}