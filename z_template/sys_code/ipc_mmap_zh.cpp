#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <string.h> 
#include <sys/mman.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <iostream>

static const int MAX_INPUT_LENGTH = 20;
using namespace std; 

int main(int argc, char** argv) { 
  //  pid_t pid ;
 //   pid = fork();
//    cout<<"PID: "<<pid<<endl;

    int fd; 
    char * shared_mem; 

    fd = open(argv[1], O_RDWR | O_CREAT); 
    shared_mem = (char *)  mmap(NULL, MAX_INPUT_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
    close(fd); 


    if (!strcmp(argv[2], "read")) {
	// >> ./a.out res.log read
	// then wait to see the content from "write" mode 
	while(1) { 
	    shared_mem[MAX_INPUT_LENGTH-1] = '\0'; 
	    printf("read %s", shared_mem); 
	    sleep(1); 
	} 
    } 
    else if (!strcmp(argv[2], "write")){ 
	// >> ./a.out res.log write 
	// then input
	// >> whatever you want 
	while (1){ 
	    fgets(shared_mem, MAX_INPUT_LENGTH, stdin); 
	    printf("write %s", shared_mem);
	} 
    } 
    else{ 
	printf("Unrecognized command\n");
    } 
    return 0; 
}
