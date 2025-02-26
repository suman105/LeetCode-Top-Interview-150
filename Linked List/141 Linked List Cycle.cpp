class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *slow,*fast;
            slow=fast=head;
    
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast)    return true;
            }
            return false;
        }
    };