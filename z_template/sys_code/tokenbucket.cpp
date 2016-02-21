#include<iostream>
#include<unistd.h>

using namespace std;


pthread_mutex_t mtx;
pthread_cond_t cv_empty, cv_fill;

class bucket{
public:

    int max_capacity ;
    int get_num;
    int gen_token;
    int gen_time;
    int left;
    int get_time ;

    bucket( int mc , int gen_num, int gen_t , int get_n, int get_t ){
	max_capacity = mc;
	gen_token = gen_num;
	gen_time = gen_t;
	left = 0;
	get_num = get_n;
	get_time = get_t;

    }

    static void * gen( void * arg){
	bucket * it = (bucket * ) arg;
	int gt_ = it->gen_token;
	int t_ = it->gen_time;
	while(1){
	    cout<<endl;
	    cout<<"gen() thread id #"<<pthread_self();
	    cout<<" generate " << gt_ << " token";
	    cout<<endl;

	    pthread_mutex_lock(&mtx);

	    // it->left is the shared variable
	    while( it->max_capacity == it->left )
		pthread_cond_wait( &cv_empty, &mtx);
	    
	    it->left += gt_;
	    pthread_cond_signal(&cv_fill);
	    pthread_mutex_unlock(&mtx);

	    sleep( t_ );
	}
	return 0;
    }

    static void * get( void * arg ){
	bucket * it = (bucket * ) arg;
	while(1){
	    cout<<endl<<"get token # "<< it->get_num <<"  | left tokens: "<< it->left<<endl;
	    pthread_mutex_lock(&mtx);
	    // it->left is the shared variable
	    while( it->left < it->get_num  ) { // while( !condition){ }
		cout<<endl;
		cout<<"waiting "<<endl;
		pthread_cond_wait( &cv_fill, &mtx);
	    }
	    it->left -= it->get_num; 
	    cout<<endl<<"Thread #"<<pthread_self() <<" fetches "<< it->get_num <<" token sucessfully. "<<endl;
	    pthread_cond_signal( &cv_empty);
	    pthread_mutex_unlock(&mtx);
	    sleep( it->get_time);
	}
	return 0;
    }

};

int main(){
    cout<<"token bucket simulation"<<endl;

//    int x = 1;
//   char * y =  ((char *) &x);
//    printf("%c\n", (*y +48) );

    pthread_mutex_init ( &mtx, NULL);
    pthread_cond_init ( &cv_empty, NULL);
    pthread_cond_init ( &cv_fill, NULL);
    pthread_t pgen1, pgen2, pget1, pget2;
    bucket bkt(10, 1, 1, 10, 2 );
    bucket * pbkt = & bkt;
    pthread_create(&pgen1, NULL, bkt.gen, (void *) pbkt);
    sleep(1);
    pthread_create(&pgen2, NULL, bkt.gen, (void *) pbkt);
    sleep(3);
    pthread_create(&pget1, NULL, bkt.get, (void *) pbkt);
    sleep(1);
    pthread_create(&pget2, NULL, bkt.get, (void *) pbkt);
    pthread_join(pgen1, NULL);
    pthread_join(pgen2, NULL);
    pthread_join(pget1, NULL);
    pthread_join(pget2, NULL);

    return 0;
}


