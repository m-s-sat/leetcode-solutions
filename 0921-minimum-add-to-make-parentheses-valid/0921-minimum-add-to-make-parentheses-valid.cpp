class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, ans =0;
        for(auto ch:s){
            if(ch=='(') open++;
            else{
                if(open>0) open-- ;
                else ans++;
            }
        }
        return ans+open;
    }
};