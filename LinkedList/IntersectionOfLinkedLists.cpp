ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        
        ListNode *a=headA;
        ListNode *b=headB;
        
        while(a!=b) {
            a = a==NULL? headB: a->next;
            b = b==NULL ? headA: b->next;
        }
        return a;
    }

/*
class Solution{
  public:
    Node* findIntersection(Node* headA, Node* headB)
    {
        if(headA==NULL || headB==NULL) return NULL;
        
        map<int,int> mp;
        Node *head = new Node(-1);
        Node *temp=head;
        
        while(headB!=NULL) {
            mp[headB->data] = 1;
            headB = headB->next;
        }
        
        while(headA!=NULL) {
            if(mp.find(headA->data)!=mp.end()) {
                Node *newNode = new Node(headA->data);
                temp->next = newNode;
                temp=temp->next;
            }
            headA=headA->next;
        }
        
        return head->next;
        
    }
};

 */

