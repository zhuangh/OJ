#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int findKthLargest1(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	return nums[nums.size()-k];
    }

    int findKthLargest2(vector<int>& nums, int k) {

        priority_queue<int > Q;
	for( auto it : nums){
	    Q.push(it);
	}
	for(int i = 0 ; i<k-1;i++){
	    Q.pop();
	}
	return Q.top();

    }

    int findKthLargest3(vector<int>& nums, int k) {

	make_heap(nums.begin(), nums.end());
	for(int i = 0 ; i<k-1;i++){
	    pop_heap(nums.begin(), nums.end());
	    nums.pop_back();
	}
	return nums[0];

    }

    int partition(vector<int> &nums, int ll,  int hh, int &k ){ //, vector<int> & low, vector<int> & high){
	int pivot = nums[ll] ;
	int low   = ll     ;
	int high  = hh       ;

	if ( low >= high) return pivot;

	int tmp = nums[hh] ; 
	nums[hh] = pivot;
	nums[ll] = tmp;
	high-- ;

	while( low < high){
	    if( pivot >= nums[high] ) {
		high--;
	    }
	    else{
		int tmp = nums[high] ;
		nums[high] = nums[low];
		nums[low] = tmp;
		low++;
	    }
		for( int l = ll ; l <= hh ; l++){
		    cout<<nums[l] <<" ";
		}
		cout<<endl;
	}

	if ( nums[low] < pivot ) 
	{
	    nums[hh] = nums[low];
	    nums[low] = pivot;
	}
	k = low;
	
	cout<<" pivot value :  " << pivot <<endl;

	for( int l = 0 ; l <= nums.size() ; l++){
	    cout<<nums[l] <<" ";
	}

	cout<<" pivot id : " << k << "; value = "<< nums[k] <<endl;
	cout<<endl;
	return pivot;
    }
    int quickpick( int k, vector<int> nums, int low, int high ){
	int mid = -1;
	int pivot = partition(nums, low , high, mid);


	cout<<" find k " <<k<<" @"<<low<<", "<<high<<endl;

	if(  mid == k ) return nums[mid-1];
	else if (  mid < k  ) {
	    return quickpick( k - mid   , nums, mid  , high ); 
	}
	else{
	    return quickpick( k  , nums, low, mid - 1 ); 
	}
    }
    

    int qpick( int k , vector<int>& nums, int startn, int endn){
	int pivot = nums[startn];
	int low = startn;
	int high = endn;

	while( low < high ){

	    while( low < high && pivot > nums[high] ) high--;
	    while( low < high && pivot <= nums[low] ) low++;
	    
	    int tmp = nums[low];
	    nums[low]=nums[high];
	    nums[high]=tmp;

	    if( low >= high ) break;
	}
//	cout<<k<<endl;

	nums[startn] = nums[low];
	nums[low]    = pivot;


	/*
	for( auto it : nums ) cout<<it<<" " ;
	cout<<endl;

	cout<<k<<" -- low "<<startn<<" high "<<endn<<endl;
	for( int i = startn ; i <= endn; i++) cout<<nums[i]<< " ";


	cout<<" | k = "<<k <<" | pivot id: "<< low <<" pivot "<< pivot<<"  --- " ;
	cout<< " @ " ; 
	
	for( int i = 0 ; i < nums.size(); i++) cout<<nums[i]<< " ";
	cout<<endl;
	*/
	

	if ( k - 1  > low - startn  )
	{
//	    cout<< k - 1 - low << " @ " << low + 1 << " "<<endn<<endl;
	    return qpick( k - 1  - (low  - startn) , nums, low + 1 , endn); 
	}
	else if ( k - 1   < low - startn)
	{
//	    cout<< k  << " @ " << startn << " "<< low - 1 <<endl;
	    return qpick(k , nums, startn, low -1   ); 
	}
	else return nums[ low ]; // k - 1  == low 
    }





    int qqpick( int k , vector<int>& nums, int startn, int endn){

	int s_id = startn;
	int e_id = endn;


	while(1){
	    int low   = s_id; 
	    int high  = e_id;
	    int pivot = nums[s_id];

	    // cout<<k;
	    // cout<<" @s "<<s_id<<" e "<<e_id<<endl;
	    if( s_id > e_id ) break; 
	    while( low < high ){

		while( low < high && pivot > nums[high] ) high--;
		while( low < high && pivot <= nums[low] ) low++;

		int tmp = nums[low];
		nums[low]=nums[high];
		nums[high]=tmp;

		if( low >= high ) break;
	    }

	    nums[s_id] = nums[low];
	    nums[low]    = pivot;

	    /*
	    for( auto it : nums) 
		cout<<it<<" ";

	    cout<<" | pivot "<< low <<endl;
	    */

	    if ( k - 1  > low - s_id  )
	    {
		k = k - 1 - (low - s_id);
		s_id = low + 1;
		// return qpick( k - 1  - (low  - startn) , nums, low + 1 , endn); 
	    }
	    else if ( k - 1   < low - s_id)
	    {
		e_id = low-1;
		// return qpick(k , nums, startn, low -1   ); 
	    }
	    else return pivot;// nums[ low ]; // k - 1  == low 
	}
    }




    int findKthLargest(vector<int>& nums, int k) { 
//	return qpick(k, nums, 0 , nums.size() - 1); 
	return qqpick(k, nums, 0 , nums.size() - 1 );
    }
};

int main(){
    Solution a ; 
    int k =  3 ;
    vector<int> nums = { 8,7,9,1,3,4,2,5,6};
    //vector<int> nums={ };
    cout<<a.findKthLargest( nums, k)<<endl;
    return 0;
}

