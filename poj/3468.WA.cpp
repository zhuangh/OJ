#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>

typedef long long LL;

using namespace std;

struct SegTreeNode{
    LL subsum; 
    LL inc; //
    int lnum, rnum;
    SegTreeNode * left;
    SegTreeNode * right;
    SegTreeNode(): subsum(0), inc(0), lnum(0), rnum(0), left(NULL), right(NULL) {};
};

class NumArray {
    int z_CONST;
    vector<int> * num;
    SegTreeNode * tree_root;
    SegTreeNode * tree_seg_array ; 
    
public:
    NumArray(vector<int> &nums) {
	num = &nums;
	z_CONST = 1;

	if( num->size() >= z_CONST ) {
	   tree_seg_array = new SegTreeNode [num->size() *4 ]; 
	   // log N 
	   SegTreeNode tree;
	   tree_root = &(tree_seg_array[0]);
	   BuildSegTree(  tree_root , 0 ,  num->size() - 1, 0 );
	}
    }

    ~NumArray(){
	if( num->size() >= z_CONST) 	delete [] tree_seg_array; 
    }

    void updateSegTree(SegTreeNode * root, int i , int j , int delta){
	int mid = (root->lnum + root->rnum)/2;
//	printf("root->lnum = %d, root->rnum=%d, i=%d, mid=%d, j=%d\n", root->lnum, root->rnum, i,mid, j);
	if( root->lnum == i && root->rnum == j) {
	    root->inc += delta ;
	    return;
	} 
	root->subsum += delta*(j-i+1);

	if( j <= mid ) updateSegTree(root->left, i, j, delta);  
	else if ( i>mid)  updateSegTree(root->right, i, j, delta);  
	else {
	    updateSegTree(root->left, i, mid, delta);  
	    updateSegTree(root->right, mid+1, j, delta);  
	}
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

    LL CalSubsum( int i , int j){
	LL sum = 0 ; 
	for( int k = i; k <= j ; k++){
	    sum += (*num)[k];
	} 
	return sum;
    }

    void update(int i , int val){
	if( num->size() < z_CONST) { updateLTE(i, val); return ;}
	if( i < num->size() && i >= 0 ){
	    LL delta = val -  (*num)[i] ; 
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

    LL sumRange(int i , int j){
	if( num->size() < z_CONST) {
	   return sumRangeLTE(i, j);
	}

	if( j< num->size()) {
	    return sumRangeHelper(tree_root,  i , j); 
	}
    }

     LL sumRangeHelper( SegTreeNode * root, int i , int j){
	//	if(root == NULL) return ; 
	if ( i == root->lnum && j == root->rnum) {
	    return root->subsum + (j-i+1) * root->inc; 
	} 

	int mid = (root->lnum+ root->rnum)/2;
	root->subsum += (j-i+1)*root->inc;

	root->left->inc += root->inc;
	root->right->inc += root->inc;
	root->inc = 0; 

	/*
	if( root->inc > 0){
	    if( j <= mid ) updateSegTree( root->left, i, j , root->inc);
	    else if( i >  mid ) updateSegTree( root->right, i, j , root->inc);
	    else{
		updateSegTree( root->left, i, mid , root->inc);
		updateSegTree( root->right, mid+1,j , root->inc);
	    }
	    root->inc = 0; 
	}
	*/

	if ( j <= mid )    { return sumRangeHelper(root->left ,  i, j);  } 
	if ( i >  mid )    { return sumRangeHelper(root->right,  i, j); }
	if ( i <= mid && j > mid) {
	   return sumRangeHelper(root->left ,  i   , mid) + sumRangeHelper(root->right,  mid+1, j);
	}
    }

    void updatePOJ( int z_start, int z_end, LL delta){
	//cout<<z_start<<" -- "<< z_end<<endl;
	if( num->size() < z_CONST) { 
//	    cout<<z_start<<" -- "<< z_end<<endl;
	    for( int i = z_start ; i <= z_end ; i++){
		updateLTE(i, (*num)[i]+delta); 
	    }
	}
	else {
	    updateSegTree(tree_root, z_start, z_end, delta);  
	    /*
	       for( int i = z_start ; i <= z_end ; i++){
	       (*num)[i] += delta; 
	       SearchUpdateSegTree( tree_root, i , delta); 
	    }
	     */
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
	if ( i< num->size() ) (*num)[i] = val;
    }

   LL sumRangeLTE(int i, int j) { 
	if( j<num->size() ) {
	    LL sum =  (*num)[i];
	    for(int s = i+1 ; s <= j ; s++){
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
    int N, Q;
    cin>>N>>Q;
    vector<int> num;
    for(int i = 0 ; i < N; i++){
	int tmp;
	cin >> tmp;
	num.push_back(tmp);
    }
    NumArray sol(num);
    vector<int> results;
//    int query_num = 0;
//    sol.print();
    for(int i = 0 ; i < Q; i++){
	char opt_type;
	int a;
	int b;
	int c;
	cin>>opt_type;
	if( opt_type == 'C' ) {
	    cin>>a>>b>>c;
	    sol.updatePOJ(a-1,b-1,c);
	}
	else if(opt_type=='Q') {
	    cin>>a>>b; 
//	    results.push_back(sol.sumRange(a-1,b-1));
	    printf("%lld\n",sol.sumRange(a-1,b-1));
//	    query_num++;
	}
	else{
	    ;
	}
    }
    /*
    for(int i = 0 ; i < query_num ; i++){
	cout<<results[i]<<endl;
    }
    */
    /*
       a.print();
       cout<<a.sumRange(3,3)<<endl;
     */
    return 0;
}

