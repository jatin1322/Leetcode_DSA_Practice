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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          unordered_map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        
TreeNode* root=tree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inmap);
     return root;   
    }
    
    
TreeNode* tree(vector<int> &postorder,int poststart,int postend,vector<int> &inorder,int instart, int inend, unordered_map<int,int> &inmap){
    
     if(poststart>postend || instart>inend) return NULL;
    
    TreeNode* root=new TreeNode(postorder[postend]);
    
        int inroot=inmap[root->val];
    
        int numleft=inroot-instart;
        
root->left=tree(postorder,poststart,poststart+numleft-1,inorder,instart,inroot-1,inmap);
        
root->right=tree(postorder,poststart+numleft,postend-1,inorder,inroot+1,inend,inmap);
        
        return root;
        
    }
    

};