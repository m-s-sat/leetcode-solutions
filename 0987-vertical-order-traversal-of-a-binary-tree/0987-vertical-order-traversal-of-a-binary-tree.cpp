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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int,map<int,multiset<int>>> nodes;
        int x=0,y=0;
        q.push({root,{x,y}});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                x = q.front().second.first, y = q.front().second.second;
                nodes[y][x].insert(node->val);
                q.pop();
                if(node->left!=nullptr) q.push({node->left, {x+1,y-1}});
                if(node->right!=nullptr) q.push({node->right, {x+1,y+1}});

            }
        }
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};