class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            ListNode *slow, *fast;
            slow=fast=head;
    
            if(!head->next) return NULL;
    
            for(int i=0;i<n;i++){
                fast=fast->next;
            }
    
            if(!fast)   return head->next;
    
            while(fast->next){
                slow=slow->next;
                fast=fast->next;
            }
    
            slow->next = slow->next->next;
            return head;
        }
    };