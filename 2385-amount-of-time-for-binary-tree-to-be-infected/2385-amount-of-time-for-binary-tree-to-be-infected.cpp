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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        TreeNode* startNode = nullptr;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val == start) startNode = node;
                if(node->left){
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    mp[node->right] = node;
                }
            }
        }
        map<TreeNode*, bool> vis;
        q.push(startNode);
        int ans = 0;
        vis[startNode] = true;
        while(!q.empty()){
            int size = q.size();
            bool burnedNewNode = false;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                    burnedNewNode = true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                    burnedNewNode = true;
                }
                if(mp.find(node)!=mp.end() && !vis[mp[node]]){
                    q.push(mp[node]);
                    vis[mp[node]] = true;
                    burnedNewNode = true;
                }
            }
            if(burnedNewNode) ans++;
        }
        return ans;
    }
};