/*
Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.
*/
class Pair
{
    public:
    int ht;
    int d;
};

class Solution {
public:
    Pair diameter(TreeNode* root)
    {
        Pair p;
        if(root==NULL)
        {
            p.ht = p.d = 0;
            return p;
        }
        Pair left = diameter(root->left);
        Pair right = diameter(root->right);
        p.ht = max(left.ht,right.ht) + 1;
        p.d = max(left.ht+right.ht,max(left.d,right.d));
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Pair p = diameter(root);
        return p.d;
    }
};
