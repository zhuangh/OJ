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
private: 
    TreeNode * prev;
    TreeNode * bug1;
    TreeNode * bug0;
    int bugid ;


public:
    void recoverTreeHelp(TreeNode * root) {

	if ( root == NULL) return ;

	recoverTreeHelp(root->left);

	if( prev !=NULL &&  root->val < prev->val ){

	    if(bugid == 0 ) {
		bug0 = prev;
		bug1 = root;
//		cout<< "0: "<<bug0->val<<"";
		bugid++;
	    }
	    else{
		bug1 = root ; 
//		cout<< "1: "<<bug1->val<<"";
	    }

	}
	prev = root;



	recoverTreeHelp(root->right);
    }

    void recoverTree( TreeNode * root){
	this->bugid = 0 ; 
	this->prev = NULL;
	this->bug0 = root;
	this->bug1 = root;
	recoverTreeHelp(root);
	swap( bug0->val, bug1->val);
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

    TreeNode * root = new TreeNode ( 2); 
    root->left = new TreeNode (1);
    root->right = NULL; 
    root->left->left = NULL;
    root->left->right = new TreeNode (3);
    /*
    TreeNode * root = new TreeNode (7);
    root->left = new TreeNode (2) ;
//    root->right =  NULL ;
    root->right = new TreeNode (6) ;
    

    root->left->left = new TreeNode (1) ;
    root->left->right = new TreeNode (3) ;

    root->right->left = new TreeNode (5) ;
    root->right->right = new TreeNode (4) ;
    root->right->right->right = new TreeNode (8) ;
    */

    sol.printTree( root);
    cout<<endl;
    sol.recoverTree( root);
    cout<<endl;
    sol.printTree( root);

    return 0; 
}


