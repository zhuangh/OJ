
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
	int pz = 0 , pnz =0 ; 
	int val_size = 0;

	for( ; pnz < nums.size() ; pnz++){
	    if( nums[pnz] == val) {
		continue;
	    } 
	    nums[pz] = nums[pnz];
	    pz++;
	    val_size++;
	}
//	cout<<val_size<<endl;
	nums.resize( val_size );
	return val_size;
	/*
	for( int i = pz; i < nums.size(); i++){
	    nums[i] = val;
	}
	*/

	/*

	for(int i = 0 ; i < nums.size(); i++){
	    if(nums[i] == val) sz--;
	}
	*/
    }
};


int main(){
    Solution a;
    vector<int> nums ;
    // nums = {0, 0, 0 , 12, 0, 1412,21};
    // nums = {0, 1, 0 ,3, 12};
    // nums={4,2,4,0,0,3,0,5,1,0};
    nums ={1};
    //    nums = {0, 0, 0 ,0,0};
    a.removeElement(nums, 0);
    for( auto & it : nums){
	cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

