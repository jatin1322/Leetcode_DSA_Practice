/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* mp[101];
    void dfs(Node* node){
        
        mp[node->val]=new Node(node->val);
        for(auto it:node->neighbors){
            if(mp[it->val]==NULL){
                dfs(it);
            }
            mp[node->val]->neighbors.emplace_back(mp[it->val]);
            
        }
        
    }
    Node* cloneGraph(Node* node) {
       if(node==NULL) return node;
        if(node->neighbors.size()==0){
            Node  *copy=new Node(node->val);
            return copy;
        }
        for(int i=0;i<=100;i++){
            mp[i]=NULL;
        }
        dfs(node);
        return mp[1];
    }
};