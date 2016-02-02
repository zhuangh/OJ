#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
public:

    // counting sort and radix sort 
    void counting( vector<int> & arr , int num_base ){

	vector<int> count(10, 0 );
	vector<int> output( arr.size() , 0);

	int n = arr.size();

	// count the number
	for( int i = 0 ; i < n ; i++){
	    count[ (arr[i]/num_base)%10 ]++;
	} 

	// cumulative 
	for( int i = 1 ; i < 10 ;i++){
	    count[i] += count[i-1];
	}

	// put the  
	for( int i = n-1 ; i >= 0  ; i--){
	    output[ count [ (arr[i] / num_base)%10  ] -1  ] = arr[i]; 
	    count[ (arr[i] / num_base)%10 ]--;
	}

	for ( int i = 0 ; i < n ; i++){
	    arr[i] = output[i];
	}

    } 

    int getmax( vector<int> arr ) {
	if( arr.size() <= 0 ) return -1; 
	int mx = arr[0];
	for( int i = 1 ; i < arr.size() ; i++){
	    mx = arr[i]>mx? arr[i]:mx;
	}
	return mx;
    }

    vector<int> radixSort( vector<int> & arr ){
	int m = getmax(arr); 
	for( int num_base = 1 ; m / num_base > 0; num_base *=10){
	    counting( arr , num_base) ;
	}
	return arr;
    }
};

int main(){

    Solution a;
    vector<int> nums {10,9,1,20,3,2};

    for( auto it : a.radixSort( nums )  )
	cout<<it<<endl;

    return 0; 
}

