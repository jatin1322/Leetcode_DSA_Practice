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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      
        TreeNode* temp=root;
        TreeNode* t=new TreeNode(val);  if(root==NULL) return t;
        while(true){
            if(root->val<val){
                if(root->right==NULL){root->right=t; return temp; break;}
                root=root->right;}
            else {
             if(root->left==NULL){root->left=t; return temp;break;}   
            root=root->left;
            }
        }
        return temp;
    }
};