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
private:
    int calculate(TreeNode* node, int &maxi){
        if(node==nullptr) return 0;
        int ls = max(0,calculate(node->left, maxi));
        int rs = max(0,calculate(node->right, maxi)); 
        maxi = max(ls+rs+node->val, maxi);
        return node->val + max(ls,rs);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        calculate(root, maxi);
        return maxi;
    }
}; 