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
    ListNode* reverse2(ListNode* &head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* sub_LL=reverse2(head->next);
        head->next->next=head;
        head->next=NULL;
        return sub_LL;
        
    }
    
    void reverse(ListNode* &head,ListNode* curr,ListNode* prev){
        
        if(curr==NULL){
            head=prev;
            return;
        }
        
        ListNode* forward=curr->next;
        reverse(head,forward,curr);
        curr->next=prev;
        
        
        
    }
    ListNode* reverseList(ListNode* head) {
        return reverse2(head);
        
        
     /*  ListNode* prev=NULL;
        ListNode* curr=head;
        reverse(head,curr,prev);
        return head;
        
      */
        
        /*
              
       ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev; */
        
    }
};