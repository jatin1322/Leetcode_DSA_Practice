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
    void inorder(TreeNode* root,int &cnt,int par){
        if(root==NULL) return;
        int maxi=max(par,root->val);
      //  m[root]=maxi;
        if(maxi==root->val) cnt++;
        inorder(root->left,cnt,maxi);
        inorder(root->right,cnt,maxi);
    }
    int goodNodes(TreeNode* root) {
      //  unordered_map<TreeNode*,int> m;
        int cnt=0;
        inorder(root,cnt,root->val);
        // int cnt=0;
        // for(auto it:m){
        //     if(it.first->val==it.second) cnt++;
        // }
        return cnt;
    }
    
};