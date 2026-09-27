class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(ans.size());
            else if(s[i]==')'){
                int left = st.top();
                int right = ans.size()-1;
                while(left<=right){
                    swap(ans[left],ans[right]);
                    left++, right--;
                }
                st.pop();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};