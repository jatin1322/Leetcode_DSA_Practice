/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(unordered_map<int,Employee*> &mp,int id){
        int sum=mp[id]->importance;
        for(auto it:mp[id]->subordinates){
            sum+=dfs(mp,it);
        }
        return sum;
        
    }
    int getImportance(vector<Employee*> employ, int id) {
        unordered_map<int,Employee*> mp;
        for(auto it:employ){
            mp[it->id]=it;
        }
        return dfs(mp,id);
      
    }
};