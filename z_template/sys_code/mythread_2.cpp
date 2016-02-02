#include<pthread.h>
#include<iostream>
#include<stdio.h>

typedef struct __myarg_t {
    int a ;
    int b ;
} myarg_t;

void *mythread(void *arg){
    myarg_t *m = (myarg_t *) arg ; 
    printf("%d, %d\n", m->a, m->b);
    return NULL;
}

int main( ){
    pthread_t p [ 10];
    int rc ; 
    printf("main start \n");
    myarg_t args;    
    for( int i = 0 ; i < 9 ; i++){
	args.a = i;
	args.b = 20; 
	rc = pthread_create(&p[i], NULL, mythread, & args );
    }

    for( int i = 0 ; i < 9 ; i++){
	rc = pthread_join(p[i], NULL);
    }
    printf("main end\n");
    
    return 0;
}
