
#include<iostream>
#include<vector>

using namespace std;


struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x):val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution {
public:
    void connect( TreeLinkNode * root){

	if( root == NULL) return;

	if( root->left && root->right){
	    root->left->next = root->right;
	}

	if( root->next){

	    TreeLinkNode * left = root->right? root->right: root->left;
	    TreeLinkNode * right = NULL;
	    for( TreeLinkNode * it = root->next; it !=NULL; it=it->next){
		if( it->left ) {right = it->left; break;}
		if( it->right) {right = it->right; break;}
	    }
	    if( left ) left->next = right;
	}


	connect(root->right);
	connect(root->left);
    
    }



    void connect1(TreeLinkNode *root) {

	if( root == NULL) return;
	if( root->left == NULL){ root->next = NULL; return;}

	root->next = NULL;
	TreeLinkNode * next_line = NULL;

	if(root->right){
	    root->right->next = NULL;
	    if( root->right->left || root->right->right) next_line = root->right;
	}

	if(root->left) {	    
	    root->left->next = root->right;	  
	    if( root->left->left || root->left->right) next_line = root->left;	
	}
	cout<<next_line<<endl;

	while(next_line != NULL){
	    TreeLinkNode * cur = next_line;
	 // cout<<next_line->val<<" "<<endl;
	    TreeLinkNode * prev = NULL ;//= cur->left;
	    int flag = 0;

	    while( cur != NULL ){
	//	cout<< cur->val<<" "<<endl;

		if( cur->left ){
		    if( prev ){
			prev->next = cur->left;
		    }
		    if(flag == 0 &&  ( cur->left->left || cur->left->right ) ){flag=1; next_line = cur->left;}
		    prev = cur->left;

		}

	//	cout<<prev->val<<" "<<endl;

		if( cur->right){
		    if( prev ){
			prev->next = cur->right;
		    }
		    if(flag == 0 && ( cur->right->left || cur->right->right ) ){flag=1; next_line = cur->right;}
		    prev = cur->right;
		}
	//	cout<<prev->val<<" "<<endl;

		cur = cur->next;
	    
	    }
	    if( flag == 0 ) next_line = NULL;
	    prev->next = NULL;

	}
    }
};

int main(){
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = NULL;
    /*
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = NULL;//new TreeLinkNode(5);
    root->right->left = NULL;
    //    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    */
    Solution sol;
    sol.connect(root);
    //  sol.print(root);
    return 0;
}

