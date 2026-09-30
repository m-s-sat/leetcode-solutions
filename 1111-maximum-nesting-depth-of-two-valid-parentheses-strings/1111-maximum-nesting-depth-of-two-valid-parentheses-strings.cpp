class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans;
        ans.reserve(n);
        int depth = 0;
        for(auto ch: seq){
            if(ch=='('){
                depth++;
                ans.push_back(depth%2);
            }
            else{
                ans.push_back(depth%2);
                depth--;
            }
        }
        return ans;
    }
};