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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode* t1=l1;
        ListNode* t2=l2;
        while(t1){
            s1.push(t1->val);
            t1=t1->next;
        }
         while(t2){
            s2.push(t2->val);
            t2=t2->next;
        }
        ListNode* head = NULL;
            int carry = 0;
        while(s1.size() || s2.size() || carry){
            int sum=carry;
            if(s1.size()){sum+=s1.top(); s1.pop(); }
             if(s2.size()){sum+=s2.top(); s2.pop(); }
            ListNode* temp=new ListNode(sum%10);
            temp->next=head;
            head=temp;
            carry=sum/10;
        }
        return head;
        
    }
};