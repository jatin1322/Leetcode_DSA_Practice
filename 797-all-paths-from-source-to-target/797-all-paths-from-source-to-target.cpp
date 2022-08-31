class Solution {
public:
    void solve(int node,vector<int> &temp,vector<vector<int>> &ans,vector<vector<int>>& graph){
        if(node==graph.size()-1) {
            ans.push_back(temp);
        }
        for(auto it:graph[node]){
           temp.push_back(it);
            solve(it,temp,ans,graph);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int> temp;
        temp.push_back(0);
            solve(0,temp,ans,graph);
        return ans;
    }
};