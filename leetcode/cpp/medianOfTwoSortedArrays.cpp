#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
	int a = nums1.size();
	int b = nums2.size();
	int mid = (a+b)/2;

 
	if ( (a+b )%2 == 0) return 0.5*(findKthElt( nums1, 0,  a, nums2, 0,  b, mid)+findKthElt( nums1, 0, a, nums2, 0, b, mid + 1) ) ;
	return findKthElt( nums1,0,  a, nums2, 0, b, mid+1) ; 
    }

    double findKthElt( vector<int>& nums1, int st1, int sz1, vector<int>& nums2,int st2, int sz2, int k){

	if( sz1 > sz2 ) { 
	    return findKthElt( nums2, st2, sz2, nums1, st1, sz1, k);
	}


	if( sz1 == 0 ) return nums2[st2+k-1]; 

	if( k == 1) return min(nums1[st1], nums2[st2]);

	int pivot1 = min( k/2 , sz1); 
	int pivot2 = k - pivot1 ; 

	if( nums1[st1+pivot1-1] > nums2[st2+pivot2-1]) {
	    return findKthElt( nums1, st1,  pivot1 , nums2 , st2+pivot2, sz2 - pivot2 , k - pivot2 );
	}
	else 
	    return findKthElt( nums1, st1+pivot1 , sz1 - pivot1  , nums2 , st2, sz2 , k - pivot1);

 
    }
};

int main(){
    //vector<int> a {1,2,10,11,12};
    vector<int> a {1,2};//{1,2,3, 10};
    vector<int> b {1,2};//{4,5,6,7,8,9};
    Solution aa ;
    cout<< aa.findMedianSortedArrays( a, b)<<endl;
    return 0;
}


