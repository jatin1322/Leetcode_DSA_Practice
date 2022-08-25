class Solution {
public:
        
//     bool wordBreak(string s, vector<string>& arr) {
//        map<string,int> m;
//         for(int i=0;i<arr.size();i++){
//             m[arr[i]]++;
//         }
       
//         int flag=0;
//         solve(0,s,m,flag);
//         return flag;
//     }
    
    bool wordBreak(string s, vector<string>& arr) {
        unordered_set<string> word(arr.begin(),arr.end());
        vector<char> mem(s.size(),-1);

        return canBrk(0,s,word,mem);    
    }
    bool canBrk(int start, string& s, unordered_set<string>& wordDict,vector<char>& mem) {
        int n = s.size();
        if(start == n) return 1;
        if(mem[start]!= -1) return mem[start];
        string sub;
        for(int i = start; i<n; i++) if(wordDict.count(sub+=s[i]) && canBrk(i+1,s,wordDict,mem)) return mem[start] = 1; 
        return mem[start] = 0;
    }


};