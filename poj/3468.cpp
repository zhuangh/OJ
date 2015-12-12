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
} tree[1000100];

LL nums[100010];

class NumArray {
    LL * num;
    SegTreeNode * tree_seg_array ; 
    
public:
    NumArray( int N ) {
	num = nums;
	tree_seg_array = tree; 
	BuildSegTree( 0, 0 , N-1 );
    }


    void update( int i , int j , int delta){
	updateSegTree( 0,  i ,  j ,  delta);
    }

    void updateSegTree(int root, int i , int j , int delta){

	if( tree_seg_array[root].lnum == i && tree_seg_array[root].rnum == j) {
	    tree_seg_array[root].inc += delta;
	    return ;
	} 

	tree_seg_array[root].subsum += delta*(j-i+1);

	int mid = (tree_seg_array[root].lnum + tree_seg_array[root].rnum)/2;

	if( j <= mid ) updateSegTree(2*root+1, i, j, delta);  
	else if ( i>mid)  updateSegTree(2*root+2, i, j, delta);  
	else {
	    updateSegTree(2*root+1, i, mid, delta);  
	    updateSegTree(2*root+2, mid+1, j, delta);  
	}
    }

    void BuildSegTree(int index, int low , int high ){
	tree_seg_array[index].lnum = low;
	tree_seg_array[index].rnum = high;
	tree_seg_array[index].inc = 0;
	tree_seg_array[index].subsum = 0;

	if( low == high ) {
	    tree_seg_array[index].subsum =  num[low] ; 
	    return ; 
	}

	int mid = (low+high)/2; 
	BuildSegTree(2 * index + 1, low  , mid   ); 
	BuildSegTree(2 * index + 2, mid+1, high  ); 

	tree_seg_array[index].subsum = 
	    tree_seg_array[2*index+1].subsum 
	    + tree_seg_array[2*index+2].subsum;
    }

    void UpdateSegTree( int root, int i , int j, int delta){
	if ( i == tree_seg_array[root].lnum && j == tree_seg_array[root].rnum ){
	    tree_seg_array[root].inc += delta;
	    return ;
	}

	tree_seg_array[root].subsum += (j-i +1)* delta;

	int mid = (i + j )/2;

	if( j <= mid ) UpdateSegTree( 2*root+1, i , j, delta); 
	else if ( i>mid ) UpdateSegTree( 2*root+2 , i , j, delta); 
	else{
	    UpdateSegTree( 2*root + 1 , i , mid , delta); 
	    UpdateSegTree( 2*root + 2 , mid+1 , j, delta); 
	}
    }

    LL sumRange( int i , int j){
	return sumRangeHelper( 0, i , j);
    }

     LL sumRangeHelper( int root, int i , int j){
	if ( i == tree_seg_array[root].lnum && j == tree_seg_array[root].rnum) {
	    return  tree_seg_array[root].subsum + (j-i+1) * tree_seg_array[root].inc; 
	} 

	// printf("%d", root);
	int mid = ( tree_seg_array[root].lnum+ tree_seg_array[root].rnum)/2;
	tree_seg_array[root].subsum += (( tree_seg_array[root].rnum - tree_seg_array[root].lnum)+1)*tree_seg_array[root].inc;
	tree_seg_array[2*root+1].inc += tree_seg_array[root].inc;
	tree_seg_array[2*root+2].inc += tree_seg_array[root].inc;
	tree_seg_array[root].inc = 0 ;

	if ( j <= mid )    { return sumRangeHelper( 2*root+1 ,  i, j);  } 
	else if ( i >  mid )    { return sumRangeHelper( 2*root+2,  i, j); }
	else {
	   return sumRangeHelper(2*root+1 ,  i   , mid)
	            + sumRangeHelper(2*root+2,  mid+1, j);
	}
    }

};

int main(){
    int N, Q;
    scanf("%d%d",&N, &Q);
    for(int i = 0 ; i < N; i++){
	scanf("%lld", &nums[i]);
    }
    NumArray sol(N);
    for(int i = 0 ; i < Q; i++){
	char opt_type;
	int a;
	int b;
	int c;
	scanf("%s",&opt_type);
	if( opt_type == 'C' ) {
	    scanf("%d%d%d",&a, &b , &c);
	    sol.update(a-1,b-1,c);
	}
	else if(opt_type=='Q') {
	    scanf("%d%d",&a, &b );
	    printf("%lld\n",sol.sumRange( a-1,b-1));
	}
	else{
	    ;
	}
    }
   return 0;
}

