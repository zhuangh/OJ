#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void printList( ListNode * head ){
    ListNode * tmp ;
    tmp = head;
    while(tmp){
	cout<<tmp->val<<" ";
	tmp = tmp->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

	
	if( !head || !head->next ) return head;
	ListNode start(-1) ; 
	start.next = head; 

	ListNode * tmp_old = &start; 
	ListNode * tmp_next = head; 
	ListNode * tmp_cur = head; 

	int flag = 0 ; 

	while( tmp_next && flag < m - 1 ){
	    flag++;
	    tmp_next = tmp_cur->next;
	    tmp_old = tmp_cur;
	    tmp_cur = tmp_next;
	}

	ListNode * global_start = tmp_old;
	ListNode * global_end = tmp_next;

	while( tmp_next && flag < n && flag >= m-1 ) {
	    flag++;
	    tmp_next = tmp_cur->next;
	    tmp_cur->next = tmp_old;
	    tmp_old = tmp_cur;
	    tmp_cur = tmp_next;
	}

	global_start->next = tmp_old; // last element 
	global_end->next = tmp_cur; // last element's next 
	
	return start.next;
    }
};


int main(){
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    a.next = &b;
    b.next = &c; 
    c.next = &d; 
    d.next = &e; 
    e.next = &f; 
    f.next = &g; 


    ListNode * head = &a;

    printList( head ); 
    Solution aa ; 
    head = aa.reverseBetween(head, 1,3);
    printList( head ); 
    return 0;
}

