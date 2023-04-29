class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        
        ListNode *cur = head;
        int count=1;
        while(cur->next!=NULL) {
            count+=1;
            cur=cur->next;
        }
        cur->next = head;
        k= k%count;
        k = count-k;
        while(k--) {
            cur=cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};