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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp=head;
     while(temp){
         v.push_back(temp);
         temp=temp->next;
         
     }   
        
       int n=v.size();
        int a=1;
        int b=n-1;
    
        
        for(int i = 0; i < n; i++, head = head -> next) {
            if(i & 1)                             // odd iteration:
                head -> next = v[a++];          //        - pick node from L & update
            else                                  // even iteration
                head -> next = v[b--];          
        }
        head->next=NULL;
    }
};