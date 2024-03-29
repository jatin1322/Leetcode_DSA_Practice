/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

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
 */
class Solution {
public:
	// 876. Middle of the Linked List - returns the mid of list using slow-fast pointer approach
    ListNode* middleNode(ListNode* head) {
        auto slow = head, fast = head;
        while(fast && fast -> next)
            slow = slow -> next,
            fast = fast -> next -> next;            // fast moves at 2x speed
        return slow;                                // slow ends up at mid
    }
	// 206. Reverse Linked List - reverses and returns the head of reversed list
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while(head) {
            auto nextNode = head -> next;           // store next node before reversing next ptr of cur
            head -> next = prev;                    // reverse the next ptr to previous node
            prev = head;                            // update previous node as cur
            head = nextNode;                        // move to orignal next node
        }
        return prev;                                // returns head of reversed list
    }
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        auto mid = middleNode(head);
        auto R = reverseList(mid), L = head -> next;
        for(int i = 0; L != R; i++, head = head -> next)     // re-order in alternating fashion 
            if(i & 1) {                              
                head -> next = L;
                L = L -> next;
            }
            else {
                head -> next = R;
                R = R -> next;
            }
    }
};