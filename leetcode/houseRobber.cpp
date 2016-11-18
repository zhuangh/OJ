#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> & nums){

	// max(opt(j) + opt(j-2) , opt(j-1));
	if ( nums.size() == 0 ) return 0 ; 
	vector<int> opt ( nums.size() , 0 )  ; 
	opt[0] = nums[0]; 
	opt[1] = max( opt[0], nums[1]);

	for( int i = 2 ; i < nums.size()  ; i++){

	    opt[i] = max(opt[i-2] + nums[i] , opt[i-1]);

//	    cout<<opt[i]<<endl;
	}
//	delete []  opt;
	return opt[ nums.size() - 1] ;
    }

};


int main(){

    vector<int> nums{3,1};//{2,1,3,4,5,6};
    Solution a;
 //   for( auto it : nums) cout<< it<<endl;
    cout<<a.rob(nums)<<endl;

    return 0;
}
