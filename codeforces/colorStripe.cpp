#include<iostream>
#include<string>
#include<unordered_map>
#include<limits>

using namespace std; 

int main(){
    int k = 0;
    string target;
    string arrange="";
    unordered_map<char , int> rec ;

    cin>>k;
    cin>>target;
    

    for( int i = 0 ; i < target.size() ; i++){
	rec[target[i]]++;
    }

    int minval = std::numeric_limits<int>::max() ;
    for(auto it : rec){
	// cout<<it.first<<" "<<it.second<<endl;
//	minval = min( it.second ,minval);
	if( it.second % k != 0 ) {
	    cout<<"-1"<<endl;
	    return 0;
	}
    }

    arrange.resize( target.size() / k ); 
    int cur=0;
    for(auto it : rec){
	// cout<<it.first<<" "<<it.second<<endl;
	for(int i = 0 ; i < it.second/k ; i++){
	    arrange[cur++] = it.first; 
	}
    }
//    cout<<arrange<<endl;

    string arrange_total = arrange;
    for(int i = 0 ; i < k-1 ;i++){
	arrange_total += arrange;
    }

//    arrange = target;
    cout<<arrange_total<<endl;
    return 0;
}
