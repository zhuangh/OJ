#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
    struct mycmp{
        bool operator() (const ListNode *   a, const  ListNode *  b) const{
    	    return a->val > b->val; 
        }
    };
     
    
    ListNode * mergeKLists(vector<ListNode *> &lists) {
       int vsize = lists.size();

       if( vsize == 0 ) return NULL;
       if(vsize == 1) return lists[0];
       
       priority_queue< ListNode * , vector<ListNode * > , mycmp > minheap;  

       //ListNode * newlist = NULL;
       // ListNode * newlist_head = new ListNode(0); 
       ListNode newlist_head(0); 
       ListNode * newlist = & newlist_head;
       // newlist_head->next = newlist;

       for(int i = 0 ; i < vsize; i++){
    	   if( lists[i] != NULL) {
    	       minheap.push(lists[i]);
    	   }
       } 
	
       while (!minheap.empty())
       {
    	   ListNode * p = minheap.top();
    	   newlist->next = p ; 
    	   newlist = p;
    	   minheap.pop();
    	   if ( p->next ) minheap.push(p->next);
       }

       return newlist_head.next;
    }

    // counting sort and radix sort 
    void counting( vector<int> & arr , int num_base ){
	vector<int> count  (10,0);
	vector<int> output (arr.size(),0);
	
	int n = arr.size();
	for( int i = 0; i < n ; i++){
	    count[ (arr[i]/num_base) %10]++;
	}

	for( int i = 1 ; i < 10 ; i++){
	    count[i] += count[i-1];
	}

	for( int i = n - 1; i >=0 ;i--){
	   output[ count[ ( arr[i]/num_base) %10] -1 ] = arr[i]; 
	   count[ (arr[i]/num_base) % 10 ]--;
	}
	
	for( int i = 0 ; i < n; i++){
	    arr[i] = output[i];
	}

    } 

    int getmax( vector<int> arr ) {
	if( arr.size() <= 0 ) return -1; 
	int mx = arr[0];
	for( int i = 1 ; i < arr.size() ; i++){
	    mx = arr[i]>mx? arr[i]:mx;
	}
	return mx;
    }

    vector<int> radixSort( vector<int> & arr ){
	int m = getmax(arr); 
//	cout<<m<<endl;
	for( int num_base = 1 ; m / num_base > 0; num_base *=10){
//	    cout<<num_base<<endl;
	    counting( arr , num_base) ;
	}
	return arr;
    }
};

int main(){

    Solution a;
    vector<int> nums {10,9,1,20,3,2};

    for( auto it : a.radixSort( nums )  )
	cout<<it<<endl;

    return 0; 
}

