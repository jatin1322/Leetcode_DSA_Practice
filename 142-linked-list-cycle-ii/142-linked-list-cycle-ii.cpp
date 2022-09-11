/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode * fast=head;
        ListNode * slow=head;
        if(head==NULL || head->next==NULL ){
            return NULL;
        }
        
        do{
            fast=fast->next->next;
            slow=slow->next;
            if(fast==NULL || fast->next==NULL){
                return NULL;
            }
        }
     while(fast!=slow);
        
           slow=head;
        
        int ans=0;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
            
        }
        
        return fast;
    }
    
};