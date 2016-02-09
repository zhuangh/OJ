#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <stdio.h>

#include <fcntl.h>
#include <openssl/md5.h> 


// unsigned char result [MD5_DIGEST_LENGTH]; 

using namespace std;


void print_md5_sum(unsigned char * md ){
    for(int i = 0 ; i < MD5_DIGEST_LENGTH ; i++) 
	printf("%02x", md[i]);
}

long get_size_by_fd( int fd ){
    struct stat statbuf;
    if(fstat(fd, &statbuf ) >= 0 ) 
	return statbuf.st_size;
}

void listFilesNow( char * workingDir){
    auto dir = opendir(workingDir);
    if(dir){
	auto dirent = readdir( dir ) ;
	// Only list files, not directories
	while( dirent){
	    if ( dirent->d_type != DT_DIR ) {

		string name (dirent->d_name);
		cout << name << "\n";

		int fid = open( name.c_str()  , O_RDONLY);
		if( fid != 0 ){
		    long f_size = get_size_by_fd( fid ); 
		    cout<<" file size =  "<<f_size <<" B" ;
		    unsigned char md5_result [MD5_DIGEST_LENGTH];
		    unsigned char * file_buffer; 
		    // MD5(  file_buffer , f_size, md5_result);
		    MD5("hello word");
		    cout<< "MD5 ";
		    print_md5_sum( md5_result );
		    cout<<endl;
		}
	    }
	    else {
		string name (dirent->d_name);
		cout<<"[Dir encountered] "<< name <<endl;
		if( name != "." && name != ".." )
		    listFilesNow( dirent->d_name);
	    }
	    dirent = readdir(dir);	
	}
	closedir(dir);
    }
}

void listFilesInWorkingDirectory( ){

    // Get working directory


    char wdbuf[MAXNAMLEN];
    const auto workingDirectory = getcwd(wdbuf, MAXNAMLEN);

    // Open the directory
    const auto dir = opendir(workingDirectory);
    if (dir) {
	// Use readdir to get each element
	auto dirent = readdir(dir);
	while (dirent) {
	    // Only list files, not directories
	    if (dirent->d_type != DT_DIR) {
		string name (dirent->d_name);
		cout << name << "\n";
	    }
	    else {
		string name (dirent->d_name);
		cout<<"[Dir encountered] "<< name <<endl;

	    }
	    dirent = readdir(dir);
	}
	closedir(dir);
    }
}

int main(){
    //    listFilesInWorkingDirectory(); 
    //   cout<<endl;
    char wdbuf [ MAXNAMLEN];
    auto workingDir = getcwd( wdbuf, MAXNAMLEN);
    listFilesNow(workingDir); 
    return 0;
}

