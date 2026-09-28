class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        for(char c:s) {
            if(c=='(') {
                st.push(c);
                int st_size = st.size();
                ans = max(ans, st_size);
            }
            else if(c==')') st.pop();
            
        }
        return ans;
    }
};