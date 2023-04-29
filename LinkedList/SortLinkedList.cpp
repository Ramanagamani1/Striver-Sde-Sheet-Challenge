/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    ListNode* merge(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while(head1!=NULL && head2!=NULL) {

            if(head1->val <=  head2->val) {
                temp->next = head1;
                head1=head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        if(head1!=NULL) {
            temp->next = head1;
        }
        if(head2!=NULL) {
            temp->next = head2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) 
              return head;

        ListNode *left = head;
        ListNode *middle = getMiddle(head);
        ListNode *right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);
        ListNode *ans = merge(left,right);
        return ans;
        
    }
};