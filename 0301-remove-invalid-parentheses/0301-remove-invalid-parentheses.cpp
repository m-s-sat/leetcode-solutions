class Solution {
private:
    unordered_set<string>ans;
    void solve(string&s,int ind,int left,int right,int open,string curr){
        if(ind==s.size()){
            if(open==0&&left==0&&right==0) ans.insert(curr);
            return;
        }
        char ch=s[ind];
        if(ch=='('){
            if(left>0) solve(s,ind+1,left-1,right,open,curr);
            solve(s,ind+1,left,right,open+1,curr+ch);
        }
        else if(ch==')'){
            if(right>0) solve(s,ind+1,left,right-1,open,curr);

            if(open>0) solve(s,ind+1,left,right,open-1,curr+ch);
        }
        else solve(s,ind+1,left,right,open,curr+ch);
        
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int left=0,right=0;
        for(char ch:s){
            if(ch=='(') left++;
            else if(ch==')'){
                if(left>0) left--;
                else right++;
            }
        }
        solve(s,0,left,right,0,"");
        return vector<string>(ans.begin(),ans.end());
    }
};