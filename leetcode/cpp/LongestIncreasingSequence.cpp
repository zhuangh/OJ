#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
        int lengthOfLIS(vector<int>& nums) {

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

};

int main(){

    Solution a; 
    vector<int> num; 
//    num = {10, 9, 2, 5, 3, 7, 101, 18, 19};
    num = {1,3,6,7,9,4,10,5,6};
    cout<<a.lengthOfLIS( num)<<endl;
    return 0;
}
