

#include<iostream>
#include<algorithm>
#include<vector> 
#include<queue> 

using namespace std;
// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

	vector< vector<int> > res;
	if( root == NULL) return res;

	vector< vector<int> > rr;
	queue<TreeNode*> qa ; 
	queue<TreeNode*> qb ; 
	qb.push(root);

	while(!qb.empty()){
	    vector<int> res_tmp;
	    swap(qa,qb);

	    while( !qa.empty()){
		TreeNode * tmp = qa.front();
		qa.pop(); 
		if(tmp->left) 
		    qb.push(tmp->left);
		if(tmp->right)
		    qb.push(tmp->right);
	//	cout<<tmp->val<<endl;
		res_tmp.push_back( tmp->val);
	    }
	    res.push_back(res_tmp);
	}
	for( int i = 0 ; i  < res.size();i++){
//	    cout<<i<<endl;
	     rr.push_back( res[res.size() - 1 -i]);
	}
	return rr;
    }

};

int main(){
    Solution a; 
    TreeNode root(1);

    TreeNode l(2) ; 
    TreeNode ll(4);
    l.left=&ll;
    root.left = &l;
    TreeNode r(3);
    root.right = &r;
    vector<vector<int>> rrs=a.levelOrderBottom(&root);
cout<<    rrs.size()<<endl;
    for( auto it : rrs ){
	for(auto itt : it){
	    cout<<itt<<" ";
	}
	cout<<endl;
    }
    return 0;
}

