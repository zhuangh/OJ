
#include<stdio.h>
#include<iostream>
using namespace std;
//bool isBadVersion(int version);

bool A[ ] = {0,0, 0,0,0,0,1,1,1,1,1}; 
bool isBadVersion(int version){
    return A[version]; 
}


bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
	int left = 1; 
	int right = n; 
	int mid = 1 + (n - 1)/2 ; 

	while(left <= right){

	    bool test  =  isBadVersion(mid) ;
	    if (test && !isBadVersion(mid-1) ) return mid;
	    if (test ) {
		// go to the first half section
		right = mid - 1 ;
	    }
	    else{
		// go to the second half section 
		left = mid + 1; 
	    }
	    // cout<<"left = "<<left<<" " << "right= "<< right<<endl;
	    mid = left + (right-left)/2;
	}
	return -1;  // undefine behavior  
    }
};

int main(){
    Solution sol ; 
    cout<<sol.firstBadVersion(10)<<endl; 
    return 0;
}
