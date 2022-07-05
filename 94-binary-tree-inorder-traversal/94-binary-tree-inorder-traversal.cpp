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

// void inorder(TreeNode* root, vector<int> &v ){
//         if(root==NULL) return ;
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> v;
//         inorder(root,v);
//         return v;
//     }

class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) return ans;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                    node=node->right;
            }
        }
        
        return ans;
    }
};