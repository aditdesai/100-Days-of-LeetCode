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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> ans;
        inorder(root, ans, k);
        return ans.top();
    }

    void inorder(TreeNode *root, priority_queue<int> &ans, int k)
    {
        if (!root)
            return;

        inorder(root->left, ans, k);
        
        ans.push(root->val);
        if (ans.size() > k)
            ans.pop();

        inorder(root->right, ans, k);
    }
};