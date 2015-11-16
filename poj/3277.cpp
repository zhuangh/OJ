#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
using namespace std;



struct tree{
   int right, left, mid;
   int h;
};

int cmpfunc(const void * a, const void *b){
    return *(int *) a - * (int *) b;
}


void construct(struct tree *seg_tree, int s, int e, int num){

    seg_tree[num].left = s;
    seg_tree[num].right = e;
    seg_tree[num].mid = (s+e)/2;



    if ( s+1 == e ) {
//cout<<"["<<seg_tree[num].left<<", "<<seg_tree[num].right<<").  ";
	return;
    }
    
//    int left =(int) distance(es.begin(), lower_bound(es.begin(),es.end(),seg_tree[num].left))+1;
//    int mid = (int)distance(es.begin(), lower_bound(es.begin(),es.end(),seg_tree[num].mid))+1;
//    int right =(int) distance(es.begin(), lower_bound(es.begin(),es.end(),seg_tree[num].right))+1;
//    cout<< s<<"  "<< (s+e)/2<<"  "<<e<<endl;
     construct(seg_tree, seg_tree[num].left ,seg_tree[num].mid   , 2*num );
     construct(seg_tree,seg_tree[num].mid, seg_tree[num].right, 2*num+1 );

 //  construct(seg_tree,es, left , mid  , 2*num );
   // construct(seg_tree,es,mid, right, 2*num+1 );

}



void insert(struct tree *seg_tree ,/*vector<int> es,*/ int l ,int r, int h, int num){
    if(seg_tree[num].left == l && seg_tree[num].right ==r){
	if(seg_tree[num].h<h || !seg_tree[num].h)
	    seg_tree[num].h = h;
	return;
    }

    if(r<=seg_tree[num].mid){
	insert(seg_tree,  l,r   ,h,2*num);
    
    }
    else if (l>=seg_tree[num].mid)
    {
	insert(seg_tree, l,r,h,2*num+1);
    }
    else{
	insert(seg_tree,  l , seg_tree[num].mid ,      h, 2*num  );
	insert(seg_tree,  seg_tree[num].mid ,r,     h, 2*num+1);
    }
    return ;
}

long long cal( struct tree *seg_tree, int * myhash, int h, int num){
    if(h>seg_tree[num].h)
	seg_tree[num].h = h;
    if(seg_tree[num].left + 1 == seg_tree[num].right){
	int length = myhash[ seg_tree[num].right-1] - myhash[ seg_tree[num].left-1];
	return (long long) seg_tree[num].h * (length);
    }
    return cal(seg_tree , myhash , seg_tree[num].h,2*num) + cal(seg_tree, myhash, seg_tree[num].h,2*num+1);


}

int binarySearch(int* myhash, int sz, int ele ){

    int b = 0, e = sz-1;
    int mid ;
    while(b < e){
	mid =( b+e)/2;
	if( myhash[mid] == ele ){
	    b = e = mid ;
	}
	else if (myhash[mid] < ele ){
	    b = mid+1;
	}
	else if (myhash[mid]> ele){
            e = mid-1;	    
	}

    }
    return b + 1 ;

}


int main(){

    const int MAX = 400000  ;
    int case_num = 0;

    cin>>case_num;

    struct  tree seg_tree [MAX];
    int a, b;
    int *s = new int [case_num];
    int *e = new int [case_num];
    int *h = new int [case_num];
    int *myhash = new int [case_num*2];
    memset(s,case_num,0);
    memset(e,case_num,0);
    memset(h,case_num,0);
    memset(myhash,2*case_num, 0);

    for(int i = 0; i<case_num ; i++){
	cin>>a >>b>>h[i];
	if (a>b) {
	    s[i] = b; e[i] = a;
	}
	else{
	    s[i] = a ; e[i] =b;
	}
	myhash[2*i] = a ; myhash[2*i+1]=b;
    }

    //  for(int i = 0 ; i< 2*case_num ; i++) cout<<myhash[i]<<"  ";
    //     cout<<endl<<endl;
    qsort(myhash, (size_t) (2*case_num),(size_t) sizeof(int), cmpfunc);

    int flags=0 , myhash_sz = 1;
    
    for(int i = 1 ; i < 2*case_num; i++){
	if (myhash[i] == myhash[i-1] && flags == 1) {
	    myhash[myhash_sz]= myhash[i]; 
	    myhash_sz++;
	}
	else if (myhash[i] == myhash[i-1] && flags == 0) {
	    continue;
	}
	else if (myhash[i] != myhash[i-1]) {
	    myhash[myhash_sz] = myhash[i];
	    myhash_sz++;
	    flags = 0;
	}
    }


   // cout<<myhash_sz<<endl; 
   // for(int i = 0 ; i< myhash_sz ; i++) cout<<myhash[i]<<"  ";
    //cout<<endl;

    construct(seg_tree,  1, myhash_sz ,1 );
 
    for(int i = 0 ; i<case_num ; i++){
	insert(seg_tree, binarySearch(myhash, myhash_sz, s[i]) , binarySearch(myhash, myhash_sz, e[i])   ,h[i],1);
    }
    cout<<cal(seg_tree,myhash, 0,1)<<endl;
    return 0;
}

