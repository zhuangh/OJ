#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int a): val(a) , left(NULL), right(NULL){}
};


class Solution {
public:
    void recoverTree( TreeNode * root){

	if( root == NULL ) return ;

	stack<TreeNode *> stk;
	stk.push(root);
	TreeNode * cur; 
	TreeNode * prev = NULL; 

	TreeNode * bug = NULL;
	TreeNode * bug_col[4];
	int iter = 0;


	while( !stk.empty()){
	    cur = stk.top();

	    if( !prev || prev->left == cur || prev->right==cur){
		if( cur->left != NULL) {
		    stk.push(cur->left);
		}
		else {


		    if ( bug!=NULL && cur->val < bug->val) {
			bug_col[iter++] = bug; 
			bug_col[iter++] = cur; 
		    } 		
		    bug = cur;
		    cout<<cur->val<<" ";
		    stk.pop();
		    if( cur->right !=NULL) {
			stk.push(cur->right);
		    }
		}
	    }
	    else {
		// if ( cur->left == prev){

		if ( bug!=NULL && cur->val < bug->val) {
		    bug_col[iter++] = bug; 
		    bug_col[iter++] = cur; 
		} 

		bug = cur;
		cout<<cur->val<<" ";
		stk.pop();
		if( cur->right!=NULL) stk.push(cur->right);
	    } 


	    prev = cur;
	    }

	    cout<<endl;
	    for(int i = 0 ; i < 4;i++){
		cout<<bug_col[i]->val<< " ";
	    }
	    cout<<endl;

	    int swapval = bug_col[0]->val;
	    bug_col[0]->val= bug_col[3]->val;
	    bug_col[3]->val= swapval;
	}

	void printTree( TreeNode * root){
	    if ( root == NULL) return ;
	    printTree(root->left);
	    cout<<root->val<<" ";
	    printTree(root->right);

	}

};



int main(){
    Solution sol;

    TreeNode * root = new TreeNode (7);
    root->left = new TreeNode (2) ;
    root->right = new TreeNode (6) ;

    root->left->left = new TreeNode (1) ;
    root->left->right = new TreeNode (3) ;

    root->right->left = new TreeNode (5) ;
    root->right->right = new TreeNode (4) ;
    root->right->right->right = new TreeNode (8) ;

    sol.printTree( root);
    cout<<endl;
    sol.recoverTree( root);
    cout<<endl;
    sol.printTree( root);

    return 0; 
}


