
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
	root->left->next = root->right;
	root->right->next = NULL;
	TreeLinkNode * next_line = root->left;
	while(next_line->left != NULL){
	    //	    cout<<next_line<<" "<<endl;
	    TreeLinkNode * cur = next_line;
	    next_line =  cur->left;
	    // cout<<next_line->val<<" "<<endl;
	    while( cur != NULL ){
		if( cur->next !=NULL){
		    cur->left->next = cur->right; 
		    cur->right->next = cur->next->left;
		}else{
		    cur->left->next = cur->right; 
		    cur->right->next = NULL;
		}
		cur=cur->next;
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
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    Solution sol;
    sol.connect(root);
  //  sol.print(root);
    return 0;
}

