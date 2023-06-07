#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include <unistd.h>
sem_t db,mutex;
int rc=0;
void *reader(void *arg)
{
    int id=*((int*)arg);
    while(1){
        sem_wait(&mutex);
        rc++;
        if(rc==1)
            sem_wait(&db);
        sem_post(&mutex);
        printf("Reader %d is reading\n",id);
        sem_wait(&mutex);
        rc-=1;
        if(rc==0)
            sem_post(&db);
        sem_post(&mutex);
        sleep(1);
    }
}
void *writer(void *arg)
{
    int id=*((int*)arg);
    while(1){
        sem_wait(&db);
        printf("Writer %d is writing\n",id);
        sem_post(&db);
        sleep(1);
    }
}
void main()
{
    int i,j,read,write;
    sem_init(&mutex,0,1);
    sem_init(&db,0,1);
    printf("\nEnter the number of readers : ");
    scanf("%d",&read);
    printf("\nEnter the number of writers : ");
    scanf("%d",&write);
    pthread_t r[read],w[write];
    int rw[read],wt[write];
    for(i=0;i<read;i++){
        rw[i] = i+1;
        pthread_create(&r[i],NULL,reader,&rw[i]);}
    for(j=0;j<write;j++){
        wt[j] = j+1;
        pthread_create(&r[j],NULL,writer,&wt[j]);}
    for(i=0;i<read;i++)
        pthread_join(r[i],NULL);
    for(j=0;j<write;j++)
        pthread_join(r[j],NULL);
}