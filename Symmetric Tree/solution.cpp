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
    bool helper(TreeNode *l, TreeNode *r)
    {
        if (!l && !r)
            return true;
        if (!l || !r || l->val != r->val)
            return false;
        
        return helper(l->left, r->right) && helper(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root->left and !root->right)
            return true;
        if(!root->left or !root->right)
            return false;

        return helper(root->left, root->right);
    }
};