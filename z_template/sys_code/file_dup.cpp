#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fcntl.h>
#include "md5.h"
#include <pthread.h> 
#include <vector>

// Playground for the simple system manipulations  
// Please use with cautions 
// Designed by Hao Zhuang (Howard) 

using namespace std;

void listDupFiles( char * workingDir, vector< vector <string> > & dupf ){
    return  ; 
}

void mt_listDupFiles( char * workingDir, vector< vector <string> > & dupf ){
    return  ; 
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
//		int fid = open( name.c_str()  , O_RDONLY);
		cout<<"file name md5 = "<<md5(name)<<endl;
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
    char wdbuf [ MAXNAMLEN];
    auto workingDir = getcwd( wdbuf, MAXNAMLEN);


    auto dir = opendir(workingDir);
    if(dir){
	auto dirent = readdir( dir ) ;
	// Only list files, not directories
	while( dirent){
	    if ( dirent->d_type != DT_DIR ) {

		string name (dirent->d_name);
		cout << name << "\n";
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

int main(){
    //    listFilesInWorkingDirectory(); 
    //   cout<<endl;
    char wdbuf [ MAXNAMLEN];
    auto workingDir = getcwd( wdbuf, MAXNAMLEN);

    // output = [  
    // ["/foo/bar.png", "/foo2/images/foobar.png"] 
    // ["/foo/bar2.png", "/foo2/image2s/foobar2.png", "/foo/bar/2.png"] 
    // ]

    vector< vector< string > > dupfile; 

    listFilesInWorkingDirectory( ); 
    /*
    listFilesNow(workingDir); 
    listDupFiles(workingDir, dupfile); 
    mt_listDupFiles(workingDir, dupfile); 
    */

    // hit log simulation  

    // web crawler simulation 

    return 0;
}

