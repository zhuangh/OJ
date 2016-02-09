#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <stdio.h>
#include <fcntl.h>
#include "md5.h"
#include <pthread.h> 
#include <vector>
#include <sys/stat.h>
#include <ctime> 
//#include <sha.h>

// Simulation problems 

// Playground for the simple system manipulations  
// Please use with cautions 
// Designed by Hao Zhuang (Howard) 

using namespace std;

pthread_mutex_t mtx ; 
std::hash<string> hs; 
std::unordered_map< string , vector<string> > same_files; 
//std::map< string , vector<string> > same_files; 



void listDupFiles( char * workingDir, vector< vector <string> > & dupf ){
    return  ; 
}

void mt_listDupFiles( char * workingDir, vector< vector <string> > & dupf ){
    return  ; 
}

void listFilesNow( string workingDir, string location){
    // DFS traverse the whole ./workingDir
    auto dir = opendir(workingDir.c_str() );

    cout<<dir<<endl;
    if(dir){
	auto dirent = readdir( dir ) ;
	// Only list files, not directories
	while( dirent){
	    //cout<<"?"<<endl;

	    if ( dirent->d_type != DT_DIR ) {
		string name (dirent->d_name);
		string wholepath = (workingDir+"/"+name);
		cout << wholepath << "\n";
		struct stat var; 
		int ret = stat(wholepath.c_str(), & var);
		if( ret<0) { cout<<"weird!!!"<<endl;}
		else {
		    /*
		    cout<<"device id: " <<var.st_dev<<endl;
		    cout<<"inode: " <<var.st_ino<<endl;
		    cout<<"size : "<< var.st_size<<endl;
		    cout<<"last status of last data modification: " << var.st_mtime  <<endl;
		    cout<<"created date " << var.st_ctime  <<endl;
		    */
		}
		ifstream input(name.c_str(), std::ios::binary);
		ostringstream ost;
		ost<< input.rdbuf();
		string cont ( ost.str());
		same_files[ cont ].push_back( wholepath);
		input.close();
		//string cmd = "md5sum "+ name + " >> "+ location;
		//int res = system(cmd.c_str()); 
//		cout<<"file name md5 = "<<md5(name)<<endl;
	    }
	    else {
		string name (dirent->d_name);
		string wholepath = (workingDir+"/"+name);
		cout<<"[Dir encountered] "<< wholepath <<endl;
		if( name != "." && name != ".." )
		    listFilesNow( wholepath, location);
	    }
	    dirent = readdir(dir);	
	}
	closedir(dir);


    }
}


class Queue_z{
private:
 //   pthread_t hit_thread;
  //  pthread_t log_thread;
    int pt ;
    int size ;
    int sec; 
    int move_sample; 
    int sample; 
    vector<int> array ;
public:
    Queue_z(int sz, int se , int ms, int hs ): size(sz), array(size) , pt(0), sec(se), move_sample(ms), sample(hs) {
	/*
	front = back = -1;
	this.size = sz -1;  
	array.resize(this.size);
	for( auto it : array ) it = 0;
	*/
    }

//    virtual void * action()= 0;

    static void * move( void * arg ) {
	Queue_z * local = (Queue_z *) arg;
//	clock_t start; 
//	start = clock();
//	double duration = 0 ;
//	int pt = 0;
	while( 1 ){ 
	    cout<<"recording at array["<< local->pt<<"]="<<local->array[local->pt]<<endl;
	    int cnt=0;
	    for( auto it : local->array ) cout<<(cnt++)<<" = "<<it<<endl;
	    sleep(local->move_sample);
	    local->pt++;
	    if( local->pt >= local->size) {
		local->pt =  0;
	    }
	     pthread_mutex_lock( &mtx);
	     local->array[local->pt] = 0;
	     pthread_mutex_unlock( &mtx);
//	     pt++;
//	     pt = pt > size? 0 : pt;
	}
//	cout<<duration<<endl;
    }

    void enq(int){
    }

    void show(){

    }

    static void * hit( void * arg){
//	array[pt]++;
//	cout<<array[pt]<<" @"<<pt<<endl;
	Queue_z * local = (Queue_z*) arg;

	while( 1 ){ 
	     //cout<<"hit @"<< local->array[local->pt] <<endl;

	     pthread_mutex_lock( &mtx);
//	     cout<<pthread_self()<<endl;
	     local->array[local->pt]++;
	     pthread_mutex_unlock( &mtx);
	     int ss =  ( (rand() ) %10000)  ;
	     // cout<<"random number "<< ss <<endl; 
	     usleep( ss );
//	     pt++;
	}

    }

    void deq(){

    }

    static void  * query( void * arg){
	Queue_z * local = (Queue_z*) arg;
	while(1){
	    sleep(local->sec);
	    cout<< local->query_hits( local->sec ) <<endl;
	}
//	pthread_exit(NULL);
    }

    int query_hits( int span ){
	int nsep = span/move_sample;
	cout<< " get elements #"<< nsep<<" -- " ;
	int cnt = 0;
	int pts = pt;
	int sum = 0 ; 
	while(cnt < nsep){
	    pts--;
	    pts = pts < 0 ? size-1 : pts;
	    sum+= array[pts]; 
	    cnt++;
	}
	return sum;
    }


};


/*
class QZthread : Queue_z{

public:
    QZthread(){
	pthread_create( &tid, NULL, &run, this); 
	// int rlog = pthread_create( &log_thread, NULL, move , (void *) my_args ); 
    }
    virtual void action();
};
*/

int main(){
    //    listFilesInWorkingDirectory(); 
    //   cout<<endl;
    int option = 1; 

    if( option == 1){
	/*
	   listDupFiles(workingDir, dupfile); 
	   mt_listDupFiles(workingDir, dupfile); 
	 */
	char wdbuf [ MAXNAMLEN];

	auto workingDir = getcwd( wdbuf, MAXNAMLEN);
	string wd = "/home/zhuang/Dropbox/papers/"; 
	// output = [  
	// ["/foo/bar.png", "/foo2/images/foobar.png"] 
	// ["/foo/bar2.png", "/foo2/image2s/foobar2.png", "/foo/bar/2.png"] 
	// ]
	vector< vector< string > > dupfile; 
//	string wd(workingDir); 
	string loc = "~/tmp/tmp.log";
	listFilesNow(wd, loc); 
	for( auto it: same_files ) {
	    cout<<"[";
	    for(auto  itt : it.second){
		cout<<itt<<", ";
	    }
	    cout<<"]";
	    cout<<endl;
	}
	//    listFilesInWorkingDirectory( ); 
	//    cout<<workingDir<<endl;
    }
    else if( option == 2 ) {
	Queue_z qz(5, 10 , 5, 1);
	Queue_z * qzp = &qz; 
	pthread_t hit1, hit2 ;
	pthread_t log ;
	pthread_t query ;

	pthread_mutex_init( &mtx, NULL);
	char * msg; 

	pthread_create( &log, NULL, qz.move, (void *) qzp );
	sleep(1);
	pthread_create( &hit1, NULL, qz.hit , (void *) qzp );
	sleep(1);
	pthread_create( &hit2, NULL, qz.hit , (void *) qzp );
	pthread_create( &query, NULL, qz.query, (void *) qzp );


	pthread_join( hit1, NULL);
	pthread_join( hit2, NULL);
	pthread_join( log, NULL);
	pthread_join( query, NULL);
    }

    // hit log simulation  

    // web crawler simulation 

    return 0;
}

