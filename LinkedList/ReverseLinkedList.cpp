/* Iterative */
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node *cur = head,*prev=NULL, *next = NULL;
        while(cur!=NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
};

/* Recursive */

ListNode* Solution::reverseList(ListNode* A) {
    if (A->next==NULL)
      return A;
    ListNode *newHead=reverseList(A->next);
    A->next->next=A;
    A->next=NULL;
    return newHead;
    
}
