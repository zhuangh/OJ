#include<iostream>
#include <stdlib.h>
#include <algorithm> 
#include <vector> 

using namespace std;

// TODO: using template 

template <typename T, typename T2> 
class sortIt {
    T value;
    T2 idx; 
public:
    sortIt (): value(0), idx(0) {};
    sortIt ( T a, T b):value(a), idx(b) {};

    void assign( T a , T b){
	value = a; 
	idx = b;
    }

    void print() const {
	cout<<"idx = "<< idx <<" : val = "<< value ;
    }

    const T getVal() const {
	return value;
    }

    const T2 getIdx() const {
	return idx;
    }

    bool operator  < ( sortIt const & a ) const {
	return getVal() < a.getVal();
    }

};

template<typename T, typename T2>
bool sortItComp( sortIt<T, T2> const & a, sortIt<T, T2> const & b){
    return a.getVal() < b.getVal();
}

template<typename T, typename T2>
bool sortItCompIdx( sortIt<T, T2> const & a, sortIt<T, T2> const & b){
    return a.getIdx() < b.getIdx();
}


int main(){

    vector<sortIt<int, int> > arr(10) ;

    for( int i = 0 ; i < 10; i++){
	arr[i].assign( rand() , i ); 
	arr[i].print();
	cout<<endl;
    }

    std::sort( arr.begin() , arr.end() );
    cout<<endl;

    cout<<"sorting by value"<<endl;
    for( int i = 0 ; i < 10; i++){
	arr[i].print();
	cout<<endl;
    }

    std::sort( arr.begin() , arr.end() , sortItCompIdx<int, int> );

    cout<<endl;
    cout<<"sorting by index"<<endl;
    for( int i = 0 ; i < 10; i++){
	arr[i].print();
	cout<<endl;
    }

    return 0;
}

