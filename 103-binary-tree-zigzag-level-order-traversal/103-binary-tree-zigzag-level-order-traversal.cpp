/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=0;
        while(!q.empty()){
            
            int size=q.size();
            vector<int> level(size);
            for(int i=0; i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                
                if(flag==0)level[i]=node->val;
                else level[size-1-i]=node->val;
                if(node->left)q.push(node->left);
                 if(node->right)q.push(node->right);
            }
            flag=!flag;
            ans.push_back(level);
            
        }
        return ans;
    }
};