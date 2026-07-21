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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parentHash;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    parentHash[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parentHash[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        q.push(target);
        vector<TreeNode*> vis;
        vis.push_back(target);
        int count = 0;
        vector<int> ans;
        while(!q.empty()){
            int size = q.size();
            if(count==k){
                for(int i=0;i<size;i++){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && find(vis.begin(), vis.end(), node->left) == vis.end()){
                    q.push(node->left);
                    vis.push_back(node->left);
                }
                if(node->right && find(vis.begin(), vis.end(), node->right)==vis.end()){
                    q.push(node->right);
                    vis.push_back(node->right);
                }
                if(parentHash.find(node)!=parentHash.end() && find(vis.begin(), vis.end(), parentHash[node]) == vis.end()){
                    q.push(parentHash[node]);
                    vis.push_back(parentHash[node]);
                }
            }
            count++;
        }
        return ans;
    }
};