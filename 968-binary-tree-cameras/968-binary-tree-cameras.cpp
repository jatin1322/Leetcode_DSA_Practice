
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
     
    int ans=0;
    unordered_set<TreeNode*>covered;
    void dfs(TreeNode* root,TreeNode* par){
        
        if(!root){
            return ;
        }
        
        dfs(root->left,root);
        dfs(root->right,root);
        
        //condition 1 :if only root is present then ofc it isnt monitored so we need to add a camera
        //other 2 conditions are either of left or right child are not covered then we add camera to its parent
        if((par==nullptr && !covered.count(root)) || !covered.count(root->left)  || !covered.count(root->right) ){
            
            
            ans++;
            covered.insert(par);
            covered.insert(root);
            covered.insert(root->left);
            covered.insert(root->right);
                      
            /*
                            O-->par
                            |
                            O-->>install camera here 
                            /\     
     left child covered<<--O  O  -->right child got covered 
            */
            
            
        }
       
        
        
        
    }
public:
    int minCameraCover(TreeNode* root) {
        
        
       
        //to handle the leaf nodes as they will always be monitored by nodes above them  and its left
        // and right child is null 
        covered.insert(nullptr);
        
        dfs(root,nullptr);
        
        return ans;
        
        
     
    }
};