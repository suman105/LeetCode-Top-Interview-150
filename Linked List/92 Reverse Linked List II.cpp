class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) 
        {
            if (!head || left == right) return head;
    
            ListNode dummy(0);
            dummy.next = head;
            ListNode* prev = &dummy;
    
            for (int i = 1; i < left; ++i) {
                prev = prev->next;
            }
    
            ListNode* start = prev->next;
            ListNode* then = start->next;
    
            for (int i = 0; i < right - left; ++i) {
                start->next = then->next;
                then->next = prev->next;
                prev->next = then;
                then = start->next;
            }
    
            return dummy.next;    
        }
    };