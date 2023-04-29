ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *p1=A,*p2=B;
    ListNode *headNode=NULL,*tailNode=NULL;
    if(p1->val<p2->val){
        headNode=p1;
        tailNode=p1;
        p1=p1->down;
    }
    else{
        headNode=p2;
        tailNode=p2;
        p2=p2->down;
    }
    while(p1!=NULL && p2!=NULL){
        if(p1->val<p2->val){
            tailNode->down=p1;
            tailNode=p1;
            p1=p1->down;
        }
        else{
            tailNode->down=p2;
            tailNode=p2;
            p2=p2->down;
        }
    }
    if(p1!=NULL){
       tailNode->down=p1;
            tailNode=p1;
    }
    if(p2!=NULL){
        tailNode->down=p2;
        tailNode=p2;
    }
    return headNode;
}
ListNode* getMiddle(ListNode *head){
    if(head==NULL || head->right==NULL){
        return head;
    }
    ListNode *slow=head;
    ListNode *fast=head->right;
    while (fast && fast->right){
        slow=slow->right;
        fast=fast->right->right;
    }
    return slow;
}

ListNode* flatten (ListNode* root) {
    if(root==NULL || root->right==NULL)
           return root;
    ListNode *middle=getMiddle(root);
    ListNode* head=middle->right;
    middle->right=NULL;
    ListNode* A=flatten(root);
    ListNode* B=flatten(head);
    ListNode *newHead=mergeTwoLists(A,B);
    return newHead;
}


/* or */

Node *mergeLists(Node *a,Node *b) {
      Node *temp = new Node(0);
      Node *res = temp;
      
      while(a!=NULL && b!=NULL) {
          if(a->data<=b->data) {
              temp->bottom = a;
              temp=temp->bottom;
              a = a->bottom;
          } else {
              temp->bottom = b;
              temp = temp->bottom;
              b = b->bottom;
          }
      }
      if(a!=NULL) temp->bottom = a;
      if(b!=NULL) temp->bottom = b;
      
      return res->bottom;
}

Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL)
      return root;
      
   root->next = flatten(root->next);
   root = mergeLists(root,root->next);
   
   return root;
}
