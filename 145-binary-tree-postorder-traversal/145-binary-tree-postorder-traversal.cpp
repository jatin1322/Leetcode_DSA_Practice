
// recursive

//  void postorder(TreeNode* root, vector<int> &v ){
//         if(root==NULL) return ;
//         postorder(root->left,v);
       
//         postorder(root->right,v); 
//          v.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//          vector<int> v;
//         postorder(root,v);
//         return v;
//     }
 
// using  2 stacks 

//   vector<int> postorderTraversal(TreeNode* root) {
//          vector<int> ans;
//         if(root==NULL)return ans;
//        stack<TreeNode*> s1,s2;
//         s1.push(root);
//         while(!s1.empty()){
//             root=s1.top();
//             s2.push(root); s1.pop();
//             if(root->left)s1.push(root->left);
//                         if(root->right)s1.push(root->right);
           
            
//         }
//         while(!s2.empty()){
//             ans.push_back(s2.top()->val);
//             s2.pop();
//         }
//         return ans;

// using 1 stack tricy one

class Solution {
public:
     
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        if(root==NULL)return ans;
       stack<TreeNode*> st;
        
        TreeNode* curr=root;
        while(curr!=NULL|| !st.empty()){
            
           if(curr!=NULL){
               st.push(curr);
               curr=curr->left;
           }
        else{
           TreeNode* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top(); st.pop();
                ans.push_back(temp->val);
                while(!st.empty() && temp==st.top()->right){
                     temp=st.top(); st.pop();
                ans.push_back(temp->val);
                }
            }
            else {
                curr=temp;
            }
        }
           
            
        }
       
        return ans;
    }
};