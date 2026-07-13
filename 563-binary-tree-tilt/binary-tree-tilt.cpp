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
    int totalTilt = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int leftSum  = dfs(root->left);
        int rightSum = dfs(root->right);

        int tilt = abs(leftSum - rightSum);
        totalTilt += tilt;

        return leftSum + rightSum + root->val;
    }

public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return totalTilt;
    }
};