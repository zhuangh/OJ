
#include<iostream>
#include<vector>
using namespace std;

class Solution {

    int searchnnz( vector<int> & nums, int sz, int z_pos){
	for(int i = z_pos+1; i < sz; i++) {if(nums[i]!=0)  return i;}
	return -1;
    }

public:
    void moveZeroes(vector<int>& nums) {
	int sz = nums.size();
	if(sz == 0 || sz == 1) return;

	int nzero_cnt= 0; 
	for( int i = 0 ; i < sz ; i++){
	    if( nums[i] != 0 ) nzero_cnt++;
	}
	int z_pos = 0;
	int nnz_pos = 0;
	while(nzero_cnt >0){
	    if(nums[z_pos] != 0 )
	    {
		nzero_cnt--;
	    }
	    else
	    {
		nnz_pos = searchnnz( nums, sz, z_pos );
		if( nnz_pos == -1) break;
		nums[z_pos] = nums[nnz_pos];
		nums[nnz_pos] = 0 ; 
	    }
	    z_pos++;
	}

	for( int i = z_pos; i < sz; i++){
	    nums[i] = 0;
	}
    }
};


int main(){
    Solution a;
    vector<int> nums ;
    // nums = {0, 0, 0 , 12, 0, 1412,21};
    // nums = {0, 1, 0 ,3, 12};
    nums={4,2,4,0,0,3,0,5,1,0};
//    nums = {0, 0, 0 ,0,0};
    a.moveZeroes(nums);
    for( auto & it : nums){
	cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

