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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        if(head==NULL){
            return head;
            
        }
        ListNode* temp=head;
        while(temp->next!=NULL ){
            if(temp->next->val!=val){
                temp=temp->next;
                

            }
            \
                
           else{ while(temp->next->val==val){
               if(temp->next->next==NULL){
                  temp->next=NULL;
                   return head;
              }
                temp->next=temp->next->next;
            
            }
            }
            
         
        }
        return head;
    }
};