class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp= head;
        ListNode *slow = head, *fast=head;
        for(int i=0;i<n;i++)
            fast = fast->next;
        if(fast==NULL)
            return head->next;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

/* 
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    LinkedListNode<int> *temp= new LinkedListNode<int>(-1);
      temp->next = head;
        LinkedListNode<int> *slow = temp,*fast=temp;
     if(head==NULL || K==0)
    {
       return head;
     }
        for(int i=0;i<K;i++)
            fast = fast->next;
     
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next = slow->next->next;
        return temp->next;
}
*/