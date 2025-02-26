class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) 
        {
            if(!head)   return NULL;
            if(!k || !head->next)  return head;
            struct ListNode *temp=head;
            int cnt=0;
            while(temp){
                ++cnt;
                temp=temp->next;
            }
            if(k>cnt)   k=k%cnt;
    
            if((cnt-k == 0) || !k)  return head;
            struct ListNode *t=head,*a,*b;
            int v=cnt-k;
            while(v>1){
                t = t->next;
                --v;
            }
            a = t->next;
            t->next = NULL;
            b=a;
            while(b->next!=NULL)  b=b->next;
            b->next = head;
            return a;
        }
    };