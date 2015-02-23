class Solution {
public:
    int Onedirection( TreeNode * root, int & inner_sum ){
        if (root==NULL) return 0;
        int plsum = Onedirection(root->left,  inner_sum);
        int prsum = Onedirection(root->right, inner_sum);
    
        // inner_sum = max(plsum, prsum) ;
        int maxbranch = plsum>prsum?  max(plsum+root->val, root->val) : max(prsum+root->val, root->val);
        int res = max(maxbranch, plsum+prsum+root->val);
        inner_sum = max(res, inner_sum);
        return maxbranch; 
    }
    
    int maxPathSum(TreeNode *root) {
        int inner = std::numeric_limits<int>::min(); 
        Onedirection(root, inner);
        return inner;
    }
};
