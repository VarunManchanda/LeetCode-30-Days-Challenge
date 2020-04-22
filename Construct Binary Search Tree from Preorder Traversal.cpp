/*
Return the root node of a binary search tree that matches the given preorder traversal.
(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val,
and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of 
the node first, then traverses node.left, then traverses node.right.)
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int pre_idx = 0;
        return build(inorder, preorder, 0, inorder.size() -1, pre_idx);
    }
   TreeNode* build(vector<int> &in, vector<int> &pre, int l, int r, int &pre_idx){
        if(l > r){
            return NULL;
        }
        int idx, i;
        for(i = 0; i < in.size(); i++){
            if(in[i] == pre[pre_idx]){
                idx = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(pre[pre_idx++]);
        if(l == r){
            return root;
        }
        root->left = build(in, pre, l, idx-1, pre_idx);
        root->right = build(in, pre, idx+1, r, pre_idx);
        return root;
    }
    
};
