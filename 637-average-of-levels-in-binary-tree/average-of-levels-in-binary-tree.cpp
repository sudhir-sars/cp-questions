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
    vector<double> avg;
    vector<int> cnt;
    int mxHeight = 0;
    void dfs(TreeNode* root, vector<double>& ans, vector<double>& avg, vector<int>& cnt, int height) {
        if (root == nullptr) {
            return;
        }
        mxHeight = max(mxHeight, height);
        int oldCnt = cnt[height];
        cnt[height] += 1;
        avg[height] = 1.0 * (oldCnt * avg[height] + root->val) / cnt[height];
        dfs(root->left, ans, avg, cnt, height + 1);
        dfs(root->right, ans, avg, cnt, height + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        avg.resize(1e4 + 1, 0.0);
        cnt.resize(1e4 + 1, 0);
        dfs(root, ans, avg, cnt, 1);
        for (int i=1; i<=mxHeight; i++) {
            ans.push_back(avg[i]);
        }
        return ans;
    }
};