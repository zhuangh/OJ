
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
    void connect(TreeLinkNode *root) {

	if( root == NULL) return;
	if( root->left == NULL){ root-next = NULL; return;}

	root->next = NULL;
	TreeLinkNode * next_line = NULL;

	if(root->right){
	    root->right->next = NULL;
	    next_line = root->right;
	}
	if(root->left) {
	    root->left->next = root->right;
	    next_line = root->left;
	}


	while(next_line->left != NULL){
	    //	    cout<<next_line<<" "<<endl;
	    TreeLinkNode * cur = next_line;

	    // cout<<next_line->val<<" "<<endl;
	    TreeLinkNode * child = cur->left;
	    TreeLinkNode * targo = cur->left;

	    while( cur != NULL ){

		if( child != NULL){
		    if(targo !=NULL) {
			targo->next = child;
		    } 
		    targo = child;
		}

		if( cur->left == right){
		    cur=cur->next;
		    child = cur->left;
		}
		else{
		    child = cur->right;
		}
	    }
	}
    }
};

int main(){
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = NULL;
    //    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    Solution sol;
    sol.connect(root);
    //  sol.print(root);
    return 0;
}

