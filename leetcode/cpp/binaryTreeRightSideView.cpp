/*
* Definition for a b
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
} ;

class Solution {
public:
    void Helper( TreeNode * root, vector<int> & result, int cur, vector<int> & marked ){
	if(root == NULL) return;
	/*
	if( marked.size() == cur ){
	    marked.push_back(1);
	    result.push_back(root->val);
	}
	*/
	if ( result.size() == cur) result.push_back(root->val);
	Helper(root->right, result , cur+1, marked);  
	Helper(root->left , result , cur+1, marked); 
    }

    vector<int> rightSideView(TreeNode * root){
	vector<int> result, marked;
	if(root == NULL) return result;
	Helper(root, result, 0, marked); 
	return result;
    }
};

int main(){

    cout<<"starting"<<endl;
    TreeNode  root(1);

    TreeNode  a(2);
    root.left = &a;

    TreeNode b(3);
    root.right = &b;

    TreeNode c(5);
    a.right = &c;

    TreeNode d(4);
    b.left = &d;

    TreeNode e(7);
    d.right = &e;

    TreeNode f(6);
    c.left = &f;

    TreeNode g(9);
    f.left = &g;
    TreeNode i(10);
    f.right= &i;
    TreeNode j(11);
    g.left=&j;
    

    Solution sol; 

    vector<int> result =  sol.rightSideView(&root);
    // vector<int> result =  sol.rightSideView(NULL);

    for( int i = 0 ; i < result.size() ; i++){
	cout<<result[i]<<endl;
    }

    return 0;
}
