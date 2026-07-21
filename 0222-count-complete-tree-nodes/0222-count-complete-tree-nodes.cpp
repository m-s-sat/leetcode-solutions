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
    int fineLeftHeight(TreeNode* node){
        int count = 0;
        while(node){
            count++;
            node=node->left;
        }
        return count;
    }
    int findRightHeight(TreeNode* node){
        int count=0;
        while(node){
            count++;
            node=node->right;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh = this->fineLeftHeight(root);
        int rh = this->findRightHeight(root);
        if(lh==rh) return (1<<lh) -1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};