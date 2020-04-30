/*
Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the 
tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans =  INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root)
    {
        if(root)
        {
            int l =  dfs(root->left);
            int r =  dfs(root->right);
            ans = max({ans,root->val,l+root->val,r+root->val,l+r+root->val});
		    return max({root->val,l+root->val,r+root->val,0});
        }
        return 0;
    }
};
