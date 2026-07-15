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
    void rightView(TreeNode* node, int level, vector<int>& ans){
        if(node==nullptr) return;
        if(ans.size()==level) ans.push_back(node->val);
        rightView(node->right, level+1, ans);
        rightView(node->left, level+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        this->rightView(root,0,ans);
        return ans;
    }
};