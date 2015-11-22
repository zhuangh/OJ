#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    ListNode * next; 
    int val;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
	if( !head || !head->next ) return head;
	ListNode * tmp_old = head;
	ListNode * tmp_next = head;
	ListNode * tmp_cur = head;
	// a->b->c->d 
	tmp_next = tmp_cur->next; // b 
	tmp_cur->next = NULL; // a->next =null 
	tmp_old = tmp_cur; // b 
	tmp_cur = tmp_next;
	while(tmp_next){
	    tmp_next = tmp_cur->next ;
	    tmp_cur->next = tmp_old;
	    tmp_old = tmp_cur;
	    tmp_cur = tmp_next;
	}

	return tmp_old;

    }
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

int main(){

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    a.next = &b;
//    b.next = &c; 

    ListNode * head = &a;
    Solution aa ; 
    head = aa.reverseList(head);
    printList( head ); 
    head = aa.reverseList(head);
    printList( head ); 

    return 0; 
}
