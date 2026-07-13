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
void inorder(TreeNode* root,vector<int> &inorde){
    if(root==NULL){
        return ;
    }
    inorder(root->left,inorde);
    inorde.push_back(root->val);
    inorder(root->right,inorde);
}
    TreeNode* increasingBST(TreeNode* root) {
    vector<int> inorde;
    inorder(root,inorde);
    if (inorde.empty())
        return NULL;
    int n = inorde.size();
    TreeNode* head = new TreeNode(inorde[0]);
    TreeNode* curr = head;
    for(int i=1;i<n;i++){
        TreeNode* node = new TreeNode(inorde[i]);
        curr->left = NULL;
        curr->right = node; 
        curr=node; 
    }
    curr->left = NULL;
    curr->right = NULL;
    return head;
    }
};