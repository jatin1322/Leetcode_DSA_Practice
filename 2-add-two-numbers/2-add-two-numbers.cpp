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
        ListNode*ans=new ListNode(-1);
        ListNode*temp=ans;
        
        int carry=0;
        while(l1 or l2 or carry)
        {
            int n=carry;
            if(l1)
            {
                n+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                n+=l2->val;
                l2=l2->next;
            }
            temp->next=new ListNode(n%10);
            temp=temp->next;
            carry=n/10;
        }
        temp=ans->next;
        delete ans;
        return temp;
    }
}; 

// my try
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
         int a=l1->val+l2->val;
            int b=a%10;
            int c=a/10; 
         l1=l1->next; l2=l2->next;
        ListNode* temp=new ListNode(b);
        ListNode* temp1=temp;
        
       
        while(l1 && l2){
            
             a=l1->val+l2->val+c;
             b=a%10;
             c=a/10;
            ListNode* temp2=new ListNode(b);
            temp->next=temp2;
            temp=temp->next;
             l1=l1->next; l2=l2->next;
            
        }
        while(l1){
             a=l1->val+c;
             b=a%10;
             c=a/10;
            ListNode* temp2=new ListNode(b);
            temp->next=temp2;
            temp=temp->next;
             l1=l1->next;
        }
        while(l2){
             a=l2->val+c;
             b=a%10;
             c=a/10;
            ListNode* temp2=new ListNode(b);
            temp->next=temp2;
            temp=temp->next;
             l2=l2->next;
        }
        if(c!=0){
             ListNode* temp2=new ListNode(c);
            temp->next=temp2;
            temp=temp->next;
        }
        return temp1;
    }
};
*/