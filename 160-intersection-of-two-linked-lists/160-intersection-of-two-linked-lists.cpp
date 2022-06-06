class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2)
    {
        ListNode *t1, *t2;
        t1 = h1;
        t2 = h2;
        if(t1==nullptr && t2==nullptr){
                return NULL;
              
            }
        while (t1!=t2)
        { 
         
           
           
        
            if (t1 == nullptr)
            {
                t1 = h2;
            }
            else{
                 t1 = t1->next;
            }
            if (t2 == nullptr)
            {
                t2 = h1;
            }
           else{
                t2 = t2->next;
           }



        }
         return t1;
    }
};