class Solution {
public:
    bool canConstruct(string ra, string mag) {
        unordered_map<char,int> m;
        for(auto it: mag){
            m[it]++;
        }
        for(auto it: ra){
            m[it]--;
        }
        for(auto it: m){
            if(it.second<0) return false;
            
            
        }
        return true;
    }
};