#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
    int findHelper(vector<int> &num, int start, int end){

	if(start >= end) return 0;

	int mid = (start + end)/2;
//	cout<<num[mid] <<endl;
	if ( mid >=1 && num[mid] < num[mid-1] ) return mid;
	else if ( mid<num.size() && num[mid] > num[mid+1]) return mid+1; 

	return findHelper( num, start, mid-1 ) + findHelper(num, mid+1,end);
    }

    int findMin(vector<int> &num){
	return num[findHelper(num, 0 , num.size()-1 )];
    }
};

int main(){
    vector<int> num {4,1};
    // vector<int> num {2,1};
    Solution sol;
    cout<<sol.findMin(num)<<endl;
    return 0;
}


