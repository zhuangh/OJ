
#include<iostream>
#include<vector>

using namespace std;

class NumArray {

//    vector< vector<int> > dp ;

    vector< int > sum;
public:

    NumArray(vector<int> &nums) {
	sum.resize( nums.size()+1,0);
	sum[0] = 0;
    
	for( int i = 0 ; i < nums.size()  ;i++){
	    sum[i+1] = nums[i] + sum[i]; 
	   // cout<<sum[i]<< " ";
	}
	//cout<<sum[ nums.size() ]<< " ";
	//cout<<endl;
	/*
	dp.resize( nums.size(), vector<int>(nums.size(),0)); 
	for( int i = 0 ; i < nums.size() ; i++){
	    dp[i][i] = nums[i];
	}
	for( int i = 1 ; i < nums.size() ; i++){
	    for( int j = 0 ; j < nums.size() - i  ; j++){
		dp[j][j+i] = dp[j][i+j-1] + dp[j+i][j+i];
	    }
	}
	for( int i = 0 ; i < nums.size() ; i++){
	    for( int j = 0 ; j < nums.size() ; j++){
		cout<<dp[i][j]<<" ";
	    }
	    cout<<endl;
	}
	*/
    }

    int sumRange(int i, int j) {
//	return	dp[i][j];
	return ( sum[j+1] - sum[i] );
    }
};

int main(){

    vector<int> nums  { -2,0,3,-5,2,-1};
    NumArray numArray(nums);
    cout<<numArray.sumRange(0, 2)<<endl;;
    cout<<numArray.sumRange(2, 5)<<endl;
    cout<<numArray.sumRange(0, 5)<<endl;;
    cout<<numArray.sumRange(5, 5)<<endl;;
    cout<<numArray.sumRange(4, 4)<<endl;;
    cout<<numArray.sumRange(4, 5)<<endl;;
    cout<<numArray.sumRange(0,0)<<endl;;
    return 0;
}
