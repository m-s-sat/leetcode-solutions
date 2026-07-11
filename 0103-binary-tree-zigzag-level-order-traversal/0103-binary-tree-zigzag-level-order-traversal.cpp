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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag = 1;
        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            for (int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left != nullptr) q.push(front->left);
                if(front->right != nullptr) q.push(front->right);
                temp.push_back(front->val);
            }
            if((flag&1) == false) reverse(temp.begin(), temp.end());
            flag++;
            ans.push_back(temp);
        }
        return ans;
    }
};