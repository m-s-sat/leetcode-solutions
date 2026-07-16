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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        if(root==p) return p;
        if(root==q) return q;
        TreeNode* node1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* node2 = lowestCommonAncestor(root->right, p, q);
        if(node1 && node2) return root;
        return node1 ? node1:node2;
    }
};