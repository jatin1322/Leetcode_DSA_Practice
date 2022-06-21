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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {   if(head==nullptr || head->next == nullptr){
            return head;
        }
        ListNode *t1 = head;
 
        while (t1 != NULL && t1->next !=NULL)
        {
            if (t1->val != t1->next->val)
            {
                t1 = t1->next;
            }
            else
            {
                t1->next = t1->next->next;
            }
        }
        return head;
    }
};