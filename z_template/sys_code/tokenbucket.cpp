#include<iostream>
#include<unistd.h>

using namespace std;


pthread_mutex_t mtx;

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

	    cout<<"gen() thread id #"<<pthread_self();
	    cout<<" generate " << gt_ << " token";

	    if( it->left + gt_ <=  it->max_capacity) {
		pthread_mutex_lock( &mtx);
		it->left += gt_;
		pthread_mutex_unlock( &mtx);
	    }
	    else {
		while( it->left + gt_ > it->max_capacity ){
		    cout<<" waiting for the get() "<<endl;
		    sleep( min(t_, 1) );
		}
	    }

	    cout<<" now have "<<it->left<<endl;
	    sleep( t_ );
	    // generate r tokens every t seconds 
	}
	return 0;
    }

    static void * get( void * arg ){
	bucket * it = (bucket * ) arg;

	while(1){
	    cout<<endl<<"get token # "<< it->get_num <<"  | left tokens: "<< it->left<<endl;
	    if( it->get_num <= it->left) {
		pthread_mutex_lock( &mtx);
		it->left -= it->get_num;
		pthread_mutex_unlock( &mtx);
		cout<<"fetch "<< it->get_num <<" token sucessfully. "<<endl;
	    }  
	    else{

		// block when there is no enough resource
		while( it->left < it->get_num){
		    cout<<"get() thread id #"<<pthread_self();
		    cout<<" waiting for the new tokens"<<endl;
		    sleep( it->get_time);
		}
	    }
	    sleep( it->get_time);

	}

	return 0;
    }

};

int main(){
    cout<<"token bucket simulation"<<endl;

    pthread_mutex_init ( &mtx, NULL);
    pthread_t pgen, pget;
    bucket bkt(10, 1, 1, 10, 2 );
    bucket * pbkt = & bkt;
    pthread_create(&pgen, NULL, bkt.gen, (void *) pbkt);
    sleep(3);
    pthread_create(&pget, NULL, bkt.get, (void *) pbkt);
    pthread_join(pgen, NULL);
    pthread_join(pget, NULL);

    return 0;
}


