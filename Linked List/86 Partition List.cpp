class Solution {
    public:
        ListNode* partition(ListNode* head, int x) 
        {
            ListNode *left = new ListNode(0);
            ListNode *right = new ListNode(0);
    
            ListNode *first=left, *second=right;
    
            while(head)
            {
                if(head->val < x){
                    first->next = head;
                    first = first->next;
                }
                else{
                    second->next = head;
                    second = second->next;
                }
                head = head->next;
            }   
             
            second->next = NULL;
            first->next = right->next;
            return left->next;
        }
    };