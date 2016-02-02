#include<pthread.h>
#include<iostream>
#include<stdio.h>

void *mythread(void *arg){
    printf("%s\n", (char *) arg);
    return NULL;
}

int main( ){
    pthread_t p [ 10];
    int rc ; 
    printf("main start \n");
    for( int i = 0 ; i < 9 ; i++){
	rc = pthread_create(&p[i], NULL, mythread, (void *) ( "A" ) );
    }

    for( int i = 0 ; i < 9 ; i++){
	rc = pthread_join(p[i], NULL);
    }
    printf("main end\n");
    
    return 0;
}
