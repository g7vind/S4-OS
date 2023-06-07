#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
sem_t sp[5];
void *philosopher(void *arg){
    int i=*((int*)arg);
    sem_wait(&sp[i]);
    sem_wait(&sp[(i+1)%5]);
    printf("[PHILOSOPHER %d] : EAT USING SPOON : %d,%d\n",i,i,(i+1)%5);
    sem_post(&sp[i]);
    sem_post(&sp[(i+1)%5]);
}
void main()
{
    pthread_t p[5];
    int ph[5],i;
    for(i=0;i<5;i++){
        sem_init(&sp[i],0,1);
    }
    for(i=0;i<5;i++){
        ph[i]=i;
        pthread_create(&p[i], NULL,(void*)philosopher,&ph[i]);
    }
    for(i=0;i<5;i++){
        pthread_join(p[i], NULL);}
}