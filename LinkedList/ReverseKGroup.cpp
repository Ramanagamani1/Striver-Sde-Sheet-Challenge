ListNode *reverse_kNodes(ListNode *head,int k){
    if(head==NULL)
       return NULL;
    ListNode *next=NULL,*prev=NULL,*curr=head;
    int count=0;
    while (curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count+=1;
    }
    head->next=reverse_kNodes(curr,k);
    return prev;
} 

ListNode* Solution::reverseList(ListNode* A, int B) {
    return reverse_kNodes(A,B);
}

/*or */
class Solution {
public:
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
};


.-----------------------------------------------------------------

ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* after = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        while(true){
            ListNode* cursor = after;
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for(int i = 0; i < k; i++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
