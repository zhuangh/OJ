#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void doit(){
    fork();
    fork();
    printf("hello\n");
    return ; 
}

int main(void){
    int i; 
    /*
    for(i = 0 ; i < 2; i++){
	fork();
//	printf("-");
//	printf("ppid=%d, pid=%d, i=%d \n", getppid(), getpid(),i);
    }
    */
    doit();
    //printf("hello\n");
 //   wait(NULL);
  //  wait(NULL);
    sleep(10);
    return 0 ;
}
