/*
Ray Omoregie 

We see that this is the given solution for testing both 
producer and consumer within a buffer and has the code executing the given program.

*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 10
//Here are the given variables which are attached and 
int produce();
void put();
void *producer();
void *consumer();
void consume();
int get();
int buffer[MAX];
int theProduct;

//We see that this is the given code which is used for showing the producer class 
void *producer() {
	int r;
	while(1) {
		r = produce();
		put(r);
		sleep(1);
	}
}



//We see that this is the given code which is used for showing the consumer class 
void *consumer() {
	int r;
	while(1) {
		r = get();
		consume(r);
		sleep(1);
	}
}

//We see this returns the product and creates an increment of plus 1.
int produce() {
	return theProduct + 1;
}


//This prints out the number amount of consumer consumed integer values.
void consume(int r) {
	printf("Consumer consumed: %i\n",r);
	
}

//This prints out the number of producer values which are put in from the user.
void put(int r) {
	theProduct = r;
	printf("Producer put in: %d\n", r);
	return;
}

//This returns the given product from theProduct.
int get() {
	return theProduct;
}

void main() {
	pthread_t threads[2];
 	pthread_create(&threads[0], 0, consumer, 0);
 	pthread_create(&threads[1], 0, producer, 0);
 	pthread_join(threads[0], 0);
	pthread_join(threads[1], 0);

}