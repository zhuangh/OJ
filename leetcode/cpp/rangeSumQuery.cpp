#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct SegTreeNode{
    int subsum ; 
    int lnum, rnum;
    SegTreeNode * left;
    SegTreeNode * right;
//public:
    SegTreeNode(): subsum(0), lnum(0), rnum(0), left(NULL), right(NULL) {};
};

class NumArray {

    vector<int> * num;
    SegTreeNode * tree_root;
    SegTreeNode * tree_seg_array ; 
    
public:
    NumArray(vector<int> &nums) {
	num = &nums;

	if( num->size() >= 2 ) {
	   tree_seg_array = new SegTreeNode [num->size() *4 ]; 
	   // log N 
	   SegTreeNode tree;
	   tree_root = &(tree_seg_array[0]);
//	   cout<<"Address of tree root = @"<<tree_root<<endl;
	   BuildSegTree(  tree_root , 0 ,  num->size() - 1, 0 );
//	   cout<<"Tree build Finished"<<endl;
	}
//	cout<<"Address of tree root = @"<<tree_root<<endl;
    }

    ~NumArray(){
	if( num->size() > 2) 	delete [] tree_seg_array; 
    }

    void printAddress(){
	cout<<"Address of tree root = @"<<tree_root<<endl;
    }

    void BuildSegTree( SegTreeNode * pRoot, int low , int high, int index){

//	cout<<low<<" --- "<<high<<" with subsum = ";
    
	pRoot->lnum = low;
	pRoot->rnum = high;
	pRoot->subsum =  CalSubsum( low, high);
//	cout<<pRoot->subsum<<endl;
	if( low == high ) return ; 
	int mid = (low+high)/2; 
	/*
	SegTreeNode tmpleft, tmpright;
	pRoot->left = &tmpleft;
	pRoot->right = &tmpright;
	*/
	pRoot->left = &(tree_seg_array[2*index+1]);
	pRoot->right = &(tree_seg_array[2*index+2]);
	BuildSegTree(pRoot->left , low  , mid  , 2*index+1   ); 
	BuildSegTree(pRoot->right, mid+1, high , 2*index+2 ); 
    }

    int CalSubsum( int i , int j){
	int sum = 0 ; 
	for( int k = i; k <= j ; k++){
	    sum += (*num)[k];
	} 
	return sum;
    }

    void update(int i , int val){
	if( num->size() < 2) { updateLTE(i, val); return ;}
	if( i < num->size() && i >= 0 ){
	    int delta = val -  (*num)[i] ; 
	    (*num)[i] += delta; 
//	    cout<<"delta "<< delta<<endl;
	    SearchUpdateSegTree( tree_root, i , delta); 
	}
    }

    void SearchUpdateSegTree(SegTreeNode * root, int i , int delta){
	if( root == NULL ) return; 
	int mid = (root->lnum + root->rnum)/2;
	root->subsum += delta;
	if( i <= mid ) SearchUpdateSegTree( root->left , i , delta); 
	else SearchUpdateSegTree( root->right , i , delta); 
    }

    int sumRange(int i , int j){
	if( num->size() < 2) {
	   return sumRangeLTE(i, j);
	}

	if( j< num->size()) {
	    int sum = 0 ; 
	    sumRangeHelper(tree_root, sum , i , j); 
	    return sum;
	}
	return 0;
    }

    void sumRangeHelper( SegTreeNode * root, int & sum , int i , int j){
	if(root == NULL) return ; 

	if ( i == root->lnum && j == root->rnum) {sum+= root->subsum; return;} 

	int mid = (root->lnum+ root->rnum)/2;
	if ( j <= mid )    { sumRangeHelper(root->left , sum, i, j);  } 
	if ( i >  mid )    { sumRangeHelper(root->right, sum, i, j); }
	if ( i <= mid && j > mid) {
	    sumRangeHelper(root->left , sum, i   , mid);
	    sumRangeHelper(root->right, sum, mid+1, j);
	}
    }

    void print(){
	for( int i = 0 ; i < num->size() ;i++){
	    cout<< (*num)[i]<<" ";
	}
	cout<<endl;
    }

    void printTree(){
	if( tree_root==NULL) return;
	queue<SegTreeNode *> cur_queue;  
	queue<SegTreeNode *> next_queue;  
	cout<<tree_root->lnum<<" -- "<<tree_root->rnum<<endl;
	next_queue.push(tree_root->left); 
	next_queue.push(tree_root->right); 
	queue<SegTreeNode *> * pcur = &cur_queue ;
	queue<SegTreeNode *> * ncur = &next_queue;
//	int i= 0 ;
	while( !ncur->empty()){
//	    cout<<"pcur @" <<pcur<<endl;
//	    cout<<"ncur @"<<ncur<<endl;
	    queue<SegTreeNode *> * tcur = pcur;
	    pcur = ncur;
	    ncur = tcur;
//	    cout<<"pcur @" <<pcur<<endl;
//	    cout<<"ncur @"<<ncur<<endl;
	    while( !pcur->empty()){
		SegTreeNode * tmp = pcur->front();
		if(tmp != NULL) {
		    cout<<tmp->lnum <<" <--> "<<tmp->rnum<<" with subsum = "<<tmp->subsum<<" "<<endl; 
		    ncur->push(tmp->left);
		    ncur->push(tmp->right);
		}
//		cout<<"next queue size "<<ncur->size()<<endl;
//		cout<<"cur queue size "<<pcur->size()<<endl;
		pcur->pop();
	    }
	    cout<<endl;
	   // if( ++i == 2) break;
	}
	
    }

    // updateLTE + sunUnpdate has time complexity O(kn), where k is update times
    // and n is the problem size
    void updateLTE(int i, int val) {
	if(  num->size() <= 0 ) return ;
	if ( i< num->size() ) (*num)[i] = val;
	
    }

    int sumRangeLTE(int i, int j) { 
	if( num->size() <= 0 ) return 0;
	if( j<num->size() ) {
	    int sum =  (*num)[i];
	    for(int s = i+1 ; s < j ; s++){
		sum+= (*num)[s];
	    } 
	    //	    cout<<"in "<<sum<<endl;
	    return sum;
	}
	else return 0;
    }
    // LTE
};

int main(){

    vector<int> num;
    int tag = 0; 
    if(tag == 0 ){
	num = {};
	NumArray a(num);
	cout<<a.sumRange(0,0)<<endl;
	return 0;
    }
    if(tag == 3) {
	num = {0 ,1 ,2,3, 5,6,7,8,9 };
	NumArray a (num) ; 
	//a.print();
	//a.printAddress();
	//a.printTree(); 
	cout<<a.sumRange(0,8)<<endl;
	cout<<a.sumRange(3,5)<<endl;
	a.update(0,1);
	cout<<a.sumRange(0,8)<<endl;
	//a.printTree(); 
	a.update(8,1);

	cout<<a.sumRange(0,8)<<endl;
	//a.printTree(); 
	cout<<a.sumRange(3,3)<<endl;
    }

    if( tag == 1){
	num = {1};
	NumArray a(num);

	a.print();
	cout<<a.sumRange(0,0)<<endl;
	a.update(0,2);

	a.print();
	cout<<a.sumRange(0,0)<<endl;
    }

    if( tag == 2){
	num = {1,2};
	NumArray a(num);

	a.print();
	cout<<"result "<< a.sumRange(0,1)<<endl;
	a.update(0,2);
	a.print();
	cout<<"result "<< a.sumRange(0,1)<<endl;
    }


    /*
       a.print();
       cout<<a.sumRange(3,3)<<endl;
     */
    return 0;
}

