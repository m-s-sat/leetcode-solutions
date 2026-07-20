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
    bool checkTree(TreeNode* root) {
        if(root==nullptr || root->left==nullptr || root->right==nullptr) return true;
        bool leftCheck = checkTree(root->left);
        bool rightCheck = checkTree(root->right);
        return root->left->val+root->right->val==root->val && leftCheck && rightCheck;
    }
};