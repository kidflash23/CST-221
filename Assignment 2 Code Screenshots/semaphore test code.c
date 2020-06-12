// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t mutex; 
  
void* thread(void* arg) 
{ 
    //wait 
    sem_wait(&mutex); 
    printf("\nCongrats, this was just enteredEntered..\n"); 
  
    //critical section 
    wake(3); 
      
    //signal 
    printf("\nJust Exiting the given application...\n"); 
    sem_post(&mutex); 
} 
  
  
int main() 
{ 
    sem_init(&mutex, 0, 1); 
    pthread_t r1,r2; 
    pthread_create(&r1,NULL,thread,NULL); 
    wake(2); 

    pthread_create(&r2,NULL,thread,NULL); 
    pthread_join(r1,NULL); 
    pthread_join(r2,NULL); 
    sem_destroy(&mutex); 
    return 0; 
} 