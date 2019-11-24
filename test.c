#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <unistd.h>
#include <semaphore.h>

sem_t mutex;

typedef struct 
 {
   	int shared_table[3];
   	int i;

	
}thread_args;

void * f1(void *arg) {

	sem_wait(&mutex);
	int *res1 = malloc(sizeof(int));
	thread_args * arguments = (thread_args *) arg;
	int a = 1;
	int b = 2;
	int result = a+b;
	//arguments->shared_table[0] = 1;
	printf("%d", arguments->i);
	switch(arguments->i){
	case 0:
		arguments->shared_table[0] = result;
		arguments->i++;
		break;
	case 1:
		arguments->shared_table[1] = result;
		arguments->i += 2;
		break;
	case 3:
		arguments->shared_table[2] = result;
		arguments->i += 3;
		break;
}

	*res1 = a+b;
	arg = (void *)arguments;
	sem_post(&mutex);
	pthread_exit(NULL);

}



void * f2(void *arg) {

	sem_wait(&mutex);
	int *res1 = malloc(sizeof(int));
	thread_args * arguments = (thread_args *) arg;
	int c = 3;
	int d = 4;
	int result = c+d;
	//arguments->shared_table[0] = 1;
	printf("%d", arguments->i);
	switch(arguments->i){
	case 0:
		arguments->shared_table[0] = result;
		arguments->i++;
		break;
	case 1:
		arguments->shared_table[1] = result;
		arguments->i += 2;
		break;
	case 3:
		arguments->shared_table[2] = result;
		arguments->i += 3;
		break;
}

	*res1 = c+d;
	arg = (void *)arguments;
	sem_post(&mutex);
	pthread_exit(NULL);
}



void * f3(void *arg) {

	sem_wait(&mutex);
	int *res1 = malloc(sizeof(int));
	thread_args * arguments = (thread_args *) arg;
	int e = 5;
	int f = 6;
	int result = e+f;
	//arguments->shared_table[0] = 1;
	printf("%d", arguments->i);
	switch(arguments->i){
	case 0:
		arguments->shared_table[0] = result;
		arguments->i++;
		break;
	case 1:
		arguments->shared_table[1] = result;
		arguments->i += 2;
		break;
	case 3:
		arguments->shared_table[2] = result;
		arguments->i += 3;
		break;
}

	*res1 = e+f;
	arg = (void *)arguments;
	sem_post(&mutex);
	pthread_exit(NULL);

}


void f4(void * args){
	
	thread_args * arguments = (thread_args *) arg;
	switch(argumets->i) {
	case 3:
		
	case 5:
	case 4:
}
		
}
int main() {


	int i;
	sem_init(&mutex, 0, 1);
	thread_args *arguments;
	arguments->i = 0;

	pthread_t thread1, thread2, thread3;
	int *res_f1, *res_f2, *res_f3;
	pthread_create(&thread1, NULL, f1, arguments);
	pthread_create(&thread2, NULL, f2, arguments);
	pthread_create(&thread3, NULL, f3, arguments);
	pthread_join(thread1, (void **) &res_f1);
	pthread_join(thread2, (void **) &res_f2);
	pthread_join(thread3, (void **) &res_f3);
	//int resultat_final = *res_f1*(*res_f2)+*res_f3;

	printf("%d\n", arguments->shared_table[0]);

	




}






