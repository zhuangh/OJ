#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    // how to use c++ standard heap 
    void SwapHeapElt(vector<int> & heap, int  a , int  b){
	int tmp = heap[a];
	heap[a] = heap[b];
	heap[b] = tmp;
    }

    void Maxheapify( vector<int> & heap , int idx ){
	int heap_size =  heap.size();
	int largest = idx; 
	if( 2*idx + 1<  heap_size && heap[idx ] < heap[2*idx + 1] ) {
	    largest=  2*idx+1;
	}
	if( 2*idx + 2 <  heap_size && heap[ largest ] < heap[2*idx + 2] ) {
	    largest=  2*idx+2;
	}
	if( largest != idx ) {
	    SwapHeapElt( heap, idx, largest);
	    Maxheapify( heap, largest);
	}
    } 

    int maxheapPop( vector<int> & heap ){
	int tmp = heap.back();
	heap.pop_back();
	heap[0] = tmp;
	Maxheapify( heap, 0 );
	return heap[0];
    }

public:
    int findKthLargest(vector<int>& nums, int k) {

	int tail = nums.size();
	for ( int i = nums.size()/2-1 ; i >= 0  ; i--) 
	{
	    Maxheapify( nums, i);
	}

	int fetch ; 
	fetch = nums[0];
	for( int i = 2 ; i <= k ; i++){
	    fetch = maxheapPop(nums);
	}

	return fetch;
    }
}; 

int main(){
    Solution a ; 
    int k =  10 ;
    vector<int> nums = { 8,7,9,1,3,4,2,5,6, 10, 11};
    cout<<a.findKthLargest( nums, k)<<endl;
    return 0;
}

