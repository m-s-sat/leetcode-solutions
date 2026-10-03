class Solution {
private:
    int f(string&s,int i,vector<int>& dp){
        if(i<0)return 0;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='(')return 0;
        if(i>0&&s[i-1]=='('){
            return dp[i]=2+f(s,i-2,dp);
        }
        int len=f(s,i-1,dp);
        int open=i-len-1;
        if(open>=0&&s[open]=='('){
            return dp[i]=len+2+f(s,open-1,dp);
        }
        return 0;
    }
    
public:
    int longestValidParentheses(string s){
        int n=s.size();
        vector<int> dp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,f(s,i,dp));
        }
        return ans;
    }
};