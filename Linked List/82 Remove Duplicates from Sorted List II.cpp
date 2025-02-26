class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) 
        {
            if(!head)   return NULL;
            if(!head->next)    return head;
            struct ListNode *temp=new ListNode(0),*temp1;
            temp1=temp;
            if(head->val != head->next->val){
                temp->next = new ListNode(head->val);
                temp = temp->next;
            }
    
            struct ListNode *prev=head;
            struct ListNode *cur=head->next;
    
            while(cur->next){
                if(prev->val != cur->val and cur->val != cur->next->val){
                    temp->next = new ListNode(cur->val);
                    temp = temp->next;
                }
                prev = cur;
                cur = cur->next;
            }
            if(prev->val != cur->val){
                temp->next = new ListNode(cur->val);
                temp = temp->next;
            }
            return temp1->next;
    
        }
    };