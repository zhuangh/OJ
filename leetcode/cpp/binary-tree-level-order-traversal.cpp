#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<vector<int> > levelOrder(TreeNode *root){
	if( root == NULL) return {};

	queue<TreeNode*> q;
	queue<TreeNode*> nextq;
	vector<vector<int> > ret;
	
	vector<int> tmp;
	q.push(root);

	while(!q.empty()){
	    TreeNode * cur = q.front();
	    
	    tmp.push_back(cur->val);
	    q.pop();

	    if(cur->left != NULL) nextq.push( cur->left);
	    if(cur->right != NULL) nextq.push( cur->right);

	    if( q.empty()) {

		swap(q, nextq);
		ret.push_back(tmp);

		tmp.resize(0);
	    }

	}
	return ret;
    }

    void print( vector<vector<int> > ret ){
	//cout<<ret.size()<<endl;
	for( const auto it : ret){
	    for(const auto ity: it) {
		cout<<ity<<" ";
	    }
	    cout<<endl;
	} 
    
    }
};


int main(){
    Solution sol;
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    sol.print(sol.levelOrder(root));

    return 0;
}
