
#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode * left, * right;
    TreeNode (int x ) : val(x) , left(NULL), right(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {

	ListNode * p = node->next;
	node->val = p->val;
	node->next = p->next;
    }

    ListNode * removeElements(ListNode * head, int val){

	if(head == NULL) return head;

//	cout<<head<<endl;
	while( head != NULL && head->val == val) {
	    head = head->next;
//	    cout<<head<<endl;
	}
	if(head == NULL) return NULL;

	ListNode * it = head; 
	ListNode * p =  head;
	it = it->next;
	while( it != NULL){
	    if( it->val == val ) {
		p->next = it->next;
		it = p->next;
	    }
	    else{
		p = it;
		it=it->next;
	    }
	}
	//	cout<<head<<endl;
	return head;
    }

    int removeElement(vector<int> & nums, int val){

	int i = 0 ;
	while( i < nums.size()){
	    if( val == nums[i] ) {
		nums[i] = nums.back();
		nums.pop_back();
	    }
	    else{i++;}
	}

	return nums.size();

    }

    int searchInsert(vector<int>& nums, int target){

	int mid = nums.size()/2;
	int lo = 0 ; int hi = nums.size()-1;

	while( lo <= hi ){

	    
	    mid = (lo + hi )/2;
	    if( nums[mid] == target ) return mid;
	    else {
		if( nums[mid] < target ) {
		    lo  = mid+1 ; 
		}
		else {
		    hi = mid-1;
		}
	    }
	
	}
	return lo;
    }

    int searchInsert1(vector<int>& nums, int target){

	if(target <= nums[0] ) return 0; 
//	cout<<"size "<<nums.size()<<endl;
	int i =0;

	for( i = 1 ; i < nums.size();i++){
	    if( target >= nums[i] && target <= nums[i-1] ) return i;
	}
	
	return i;
    }


    ListNode * addTwoNumbers(ListNode *l1, ListNode * l2){

    }




    class Solution {

    public:

	    TreeNode* invertTree(TreeNode* root) {

		        

		    }

    };
};


int main(){

    ListNode a(1);
    ListNode b(1);
    ListNode c(2);
    a.next = &b ;
    b.next = &c;
    Solution aa;
    ListNode * it = aa.removeElements(&a,1);
    while( it != NULL){
	cout<<it->val<<" -- ";
	it = it->next;
    }
    cout<<endl<<endl;
    vector<int> bb ={};//  {3,1,1,1,23,44,1};
    vector<int> bbb = {1,3,5,6};
    cout<<aa.removeElement(bb, 1)<<endl<<endl;;
    cout<<aa.searchInsert( bbb , 7)<<endl;
    
    return 0;
}


