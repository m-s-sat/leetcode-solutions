class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.length();
        string ans = "";
        int pair[n];
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int j = st.top();
                st.pop();
                pair[i]=j;
                pair[j]=i;
            }
        }
        int i = 0, dir = 1;
        while(i<n) {
            if(s[i]=='('||s[i]==')'){
                i = pair[i];
                dir = -dir;
            }
            else ans.push_back(s[i]);
            i += dir;
        }
        return ans;
    }
};