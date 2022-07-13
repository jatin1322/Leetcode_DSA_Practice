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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        
TreeNode* root=tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
     return root;   
        
    }
    
TreeNode* tree(vector<int> &preorder,int prestart,int preend,vector<int> &inorder,int instart, int inend, unordered_map<int,int> &inmap){
    
     if(prestart>preend || instart>inend) return NULL;
    
    TreeNode* root=new TreeNode(preorder[prestart]);
    
        int inroot=inmap[root->val];
    
        int numleft=inroot-instart;
        
root->left=tree(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,inmap);
        
root->right=tree(preorder,prestart+1+numleft,preend,inorder,inroot+1,inend,inmap);
        
        return root;
        
    }
    
};