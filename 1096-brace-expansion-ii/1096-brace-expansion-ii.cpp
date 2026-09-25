class Solution {
public:
    string s;
    int i=0;

    set<string> parseExpression(){
        set<string> res=parseTerm();
        while(i<s.size()&&s[i]==','){
            i++;
            set<string> temp=parseTerm();
            res.insert(temp.begin(),temp.end());
        }
        return res;
    }

    set<string> parseTerm(){
        set<string> res={""};
        while(i<s.size()&&s[i]!='}'&&s[i]!=','){
            set<string> temp;
            if(s[i]=='{'){
                i++;
                temp=parseExpression();
                i++;
            }else{
                temp.insert(string(1,s[i]));
                i++;
            }

            set<string> cur;
            for(auto &a:res)
                for(auto &b:temp)
                    cur.insert(a+b);
            res=cur;
        }
        return res;
    }

    vector<string> braceExpansionII(string expression){
        s=expression;
        i=0;
        set<string> ans=parseExpression();
        return vector<string>(ans.begin(),ans.end());
    }
};