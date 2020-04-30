/*
Given a binary tree where each path going from the root to any leaf form a valid sequence, 
check if a given string is a valid sequence in such binary tree. 
We get the given string from the concatenation of an array of integers arr and the concatenation of 
all values of the nodes along a path results in a sequence in the given binary tree.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans = false;
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        string check = "";
        for(auto i : arr) check += to_string(i);
        dfs(root,check,"");
        return ans;
    }
    void dfs(TreeNode* root, string check, string s)
    {
        if(root)
        {
            if(root->left==NULL and root->right==NULL)
            {
                s+=to_string(root->val);
                if(s==check) ans = true;
                return;
            }
            s+=to_string(root->val); dfs(root->left,check,s);
            s.pop_back(); s+=to_string(root->val); dfs(root->right,check,s);
        }
    }
};
