#include<iostream>
#include<priority_queue>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


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

};

int main(){


    return 0; 
}
