ListNode* reverseKGroup(ListNode* head, int k) {
       if(head==NULL || k==1) return head;
        
       ListNode *dummy = new ListNode(0);
       dummy->next = head;
        
       ListNode *pre=dummy, *cur=dummy,*next=dummy;
       int count = 0;
    
       while(cur->next!=NULL){
           count+=1;
           cur=cur->next;
       }
    
        while(count>=k) {
            cur = pre->next;
            next = cur->next;
            
            for(int i=1;i<k;i++) {
                 cur->next = next->next;
                 next->next = pre->next;
                 pre->next = next;
                 next = cur->next;
            }
            pre = cur;
            count-=k;
        }
        return dummy->next;
    }


//or

class Solution {
public:
   

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        ListNode* temp = head;
        for(int i = 0; i < k; i++){
            if(temp == NULL) return head;
            temp = temp->next;
        }

        int count  = 0;
        while(curr!=NULL && count<k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count+=1;
        }
        if(next!=NULL) {
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};