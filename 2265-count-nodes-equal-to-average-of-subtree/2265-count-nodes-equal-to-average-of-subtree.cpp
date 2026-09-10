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
    int sum(TreeNode* root){
        if(root==nullptr) return 0;
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        return root->val+leftSum+rightSum;
    }
    int subsize(TreeNode* root){
        if(root==nullptr) return 0;
        int leftSize = subsize(root->left);
        int rightSize = subsize(root->right);
        return leftSize+rightSize+1;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int treeSize = subsize(node);
                int treeSum = sum(node);
                int avg = treeSum/treeSize;
                if(avg==node->val) cnt++;
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return cnt;
    }
};