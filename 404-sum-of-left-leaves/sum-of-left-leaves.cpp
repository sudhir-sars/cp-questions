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
    int solve( TreeNode* root ){
        int s = 0;
        if( root == nullptr ){
            return 0;
        }

        if( ( root->left != nullptr ) && root->left->left == nullptr && root->left->right == nullptr ){
            s = root->left->val;
        }
        else{
            s = solve( root->left );
        }

        s = s + solve( root->right );
        return s;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = solve( root );
        return ans;
    }
};