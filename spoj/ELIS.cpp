#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

#define STRICT_INCREASING 

using namespace std;

class IdxNum{
private:
    int value;
    int index;

public:
    IdxNum(int a , int b): value(a), index(b){};

    bool operator < ( const  IdxNum & a) const {
	return value < a.value;
    }

    int getValue() const {
	return value;
    }

    int getIndex() const {
	return index;
    }
};

class Solution {
public:
    // n^2 
        int LengthOfLIS(vector<int>& nums) {

	    if ( nums.size() == 0) return 0;
	    vector<int> seq( nums.size(), 1);
	    seq[0] = 1;
	    int max_seq = 1;

	    for( int i = 0 ; i < nums.size() ; i++){
		for( int j = 0 ; j < i ; j++){
		    if( nums[i] > nums[j] ) {
			seq[i] = seq[j]+1 > seq[i] ? seq[j]+1 : seq[i];
			max_seq = max_seq > seq[i] ? max_seq : seq[i];
		    }
		}
	    }
	    return max_seq;
	}

	// nlogn
	// also check the acm/icpc template by Jaehyun Park (poj: router) from Stanford
	// http://stanford.edu/~liszt90/acm/notebook.html#file28 
	/*
	   bool cmp ( pair<int, int> &a, pair<int, int> &b) {
	   return a.first < b.first; 
	   }
	 */

	int lengthOfLIS(vector<int>& nums) {
//	    cout<<endl;

	    if(nums.size() == 0 || nums.size() == 1  ) return nums.size();
	    vector< pair<int, int> > LIS_seq ; 
	    for( int i = 0 ;  i < nums.size(); i++){
//		cout<<nums[i] <<endl;
//		print(LIS_seq);
#ifdef STRICT_INCREASING
		pair<int, int> item = make_pair ( nums[i], 0 ) ; // watch the 0 here, 
		// assumption < 
		//    it.first < item.first
		//    it.second < it.second 
		vector<pair<int, int> >::iterator it = lower_bound( LIS_seq.begin(), LIS_seq.end(), item  ) ; 
#else
		pair<int, int> item = make_pair ( nums[i], i ) ;
		vector<pair<int, int> >::iterator it = upper_bound( LIS_seq.begin(), LIS_seq.end(), item  ) ; 
#endif
		if(  it == LIS_seq.end()) { 
		    LIS_seq.push_back( item ); 
		}
		else{
		    *it = item;
		}
	    }

	    return LIS_seq.size()  ;
	}

	void print( vector< pair<int, int> > tmp ){
	    for(int i = 0 ; i < tmp.size(); i++){
		cout<< tmp[i].first <<" " ;
	    }
	    cout<<endl;
	    for(int i = 0 ; i < tmp.size(); i++){
		cout<< tmp[i].second <<" " ;
	    }
	    cout<<endl;
	}


};

int main(){

    Solution a; 
//    num = {3,5,6,2,5,4,19,5,6,7,12};
//    num= {2,2, 2};
//    num = {1, 10, 9, 2, 5, 3, 7, 101, 18, 19};
//    num = {1,3,6,7,9,4,10,5,6};
    int n;
    cin>>n;
    vector<int> num(n); 
    for(int i = 0 ; i < num.size(); i++){
	cin>>num[i];
    }
    cout<<a.lengthOfLIS( num) <<endl;
    return 0;
}
