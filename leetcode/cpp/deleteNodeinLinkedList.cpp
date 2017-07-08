
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

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

    TreeNode* invertTree(TreeNode* root) {
	invTreehelper(root);
	return root;
    }

    TreeNode * invTreehelper( TreeNode * & root){
	if ( root == NULL) return NULL;
	
        TreeNode * tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invTreehelper(root->left);
	invTreehelper(root->right);
    }

    bool isAnagram( string s, string t){

	if( s.length() != t.length()) return false;
	if(s.length() == 0) return true;

	vector<int> alpha(26,0);
	int sum = 0;
	for( int i = 0 ; i < s.length(); i++){
	    int stmp = s[i] - 'a';
	    int ttmp = t[i] - 'a';
	    alpha[stmp]++;
	    alpha[ttmp]--;
	}

	for( int i = 0 ; i < 26 ;i++){
	    if( alpha[i] != 0) return false;
	}

	return true;
    }

    int majorityElement1(vector<int> & nums){
	map<int, int> mm ;
	for( int i = 0 ; i < nums.size() ;i++){
	    mm[nums[i]]++;
	    if(mm[nums[i]] > floor( nums.size()/2)) return nums[i]; 
	}
	return nums[0];

    }

//    vector<int> 
    int majorityElement2(vector<int> & nums){
	int cand = nums[0];
	int cnt = 1 ;
	for( int i = 1 ; i < nums.size() ;i++){
	    if( nums[i] == cand) cnt++; 
	    else {
		if( cnt < 0 ) 
		{
		    cand = nums[i];
		    cnt = 1;
		}
	    }
	    
	}
	return cand;
    }

    vector<int> majorityElement(vector<int> & nums){
	vector<int> res;
	if( nums.size() == 0 ) return res; 
	if( nums.size() == 1 ) {
	    res.push_back(nums[0]);
	    return res; 
	}
	int cand1 = 0 , cand2 = 0;
	int cnt1 = -1 , cnt2 = -1 ; 
	for( int i = 0 ; i < nums.size() ; i++){

	    if( cnt1 == -1 && nums[i] != cand2 ){
		cand1 = nums[i];
	    }
	    else if ( cnt2 == -1 && nums[i] != cand1 ){
		cand2 = nums[i];
	    }

	    if( nums[i] == cand1) {
		cnt1++;
	    }
	    else if (nums[i] == cand2){
		cnt2++;
	    }
	    else{
		cnt1--;
		cnt2--;
	    }
	}
	cnt1= 0 ; 
	cnt2 = 0 ;
	for( int i = 0 ; i < nums.size();i++){
	    if( nums[i] == cand1 ) cnt1++; 
	    else if( nums[i] == cand2 ) cnt2++; 
	}
	if( cnt1> floor(nums.size()/3) ) res.push_back(cand1);
	if( cnt2> floor(nums.size()/3) ) res.push_back(cand2);
	return res;
    }
	

    bool wordPattern( string pattern , string str){
	map<char, string> mm ;
	map<string , char> ss ;
	int j = 0;
	int cnt = 0;
	str+=' ' ;
	for( int i = 0 ; i < str.length(); i++){
	    if( str[i] == ' ' ) {
		string tmp = str.substr(j,i-j+1);
	//	cout<<tmp<<endl;
		if( mm[ pattern[cnt] ].empty() ){
		    mm[pattern[cnt]] = tmp; 
		    if( ss[tmp] == '\0' ) ss[tmp] = pattern[cnt];
		    else if ( ss[tmp] != pattern[cnt]) return false;
		}
		else {
		    if( mm[pattern[cnt]] != tmp ) return false;
		}
		cnt++;
		j = i+1;
	    }
	}
	if( cnt == pattern.length()) 
	    return true;
	return false;
    }
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
    vector<int> bbb = {2,2,5,1,2,1,1};
    vector<int> bbbb = {  1,2,2,3,2,1,1,3};
    cout<<aa.removeElement(bb, 1)<<endl<<endl;;
    cout<<aa.searchInsert( bbb , 7)<<endl;

    cout<<aa.isAnagram("cat", "cca")<<endl;
    cout<<aa.majorityElement1( bbb) <<endl;
    cout<<aa.wordPattern("abba", "dog cat cat fish")<<endl;
    cout<<aa.wordPattern("abba", "dog dog dog dog")<<endl;
    cout<<aa.majorityElement1( bbb) <<endl;

    for( auto ittt : aa.majorityElement( bbbb)){
	cout<<" -- " <<ittt<< " , ";
    } 
    cout<<endl;
    return 0;
}


