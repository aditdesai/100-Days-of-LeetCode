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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;

        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));

        pair<TreeNode *, int> curr;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();

            TreeNode *temp = curr.first;

            if (!temp->left && !temp->right)
                break;
            
            
            if (temp->left)
                q.push(make_pair(temp->left, curr.second + 1));
            if (temp->right)
                q.push(make_pair(temp->right, curr.second + 1));
        }

        return curr.second;
    }
};