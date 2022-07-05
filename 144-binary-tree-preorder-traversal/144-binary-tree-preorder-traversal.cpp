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
// recursive

// class Solution {
// public:
//     void preorder(TreeNode* root,vector<int> &v){
//          if(root==NULL){
//             return ;
//         }
       
//         v.push_back(root->val);
//         preorder(root->left,v);
//         preorder(root->right,v);
       
        
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//          vector<int> v;
       
//        preorder(root,v);
      
//       return v;  
      
//     }
// };

//iterative

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
        if(root==NULL){
         return ans;
        }
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            if(node->right){s.push(node->right);}
             if(node->left){s.push(node->left);}
            ans.push_back(node->val);
        }
        return ans;
        
     }
};
