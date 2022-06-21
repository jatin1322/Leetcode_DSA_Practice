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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
        
      ListNode* temp=head;
        
        int size=0;
        while(temp!=NULL){
            size++;
           
            temp=temp->next;
            
        }
        // cout<<size;
        if(n==size){
            ListNode* t=head;
            t=head->next;
            head->next=NULL;
            delete head;
            return t;
        }
         ListNode* t1=head;
        int a=size-n-1;
        while(a){
            t1=t1->next;
            a--;
        }
        t1->next=t1->next->next;
        
        return head;
    }
};