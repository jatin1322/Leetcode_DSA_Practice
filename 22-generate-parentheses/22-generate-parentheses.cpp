class Solution {
public:
    void generate(string &s,int open ,int close,vector<string> &ans ){
        if(open==0 && close ==0){
            ans.push_back(s);
        }
        if(open>0){
            s+="(";
            generate(s,open-1,close,ans);
            s.pop_back();
        }
        if(close>0 && open<close){
                        s+=")";
            generate(s,open,close-1,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> ans;
        int open=n,close=n;
        generate(s,open,close,ans);
        return ans;    }
};