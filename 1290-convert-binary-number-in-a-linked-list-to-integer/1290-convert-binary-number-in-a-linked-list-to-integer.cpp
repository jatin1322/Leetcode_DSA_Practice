/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
         ListNode* temp=head;
        if(head->next==NULL){
            return head->val;
        }
        
      int ans=temp->val;
       temp=temp->next;
      /*    while(temp!=NULL){
            ans=2*ans;
            ans=ans+temp->val;
            temp=temp->next;
        }*/
        while(temp!=NULL){
            
            ans=(ans<<1)|temp->val;
            temp=temp->next;
        }
        return ans; 
        
    }
};