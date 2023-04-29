ListNode* clonelist(ListNode *A) {
    ListNode *clone=A;
    ListNode *temp;
    if(A==NULL || A->next==NULL)
        return A;
    while(clone!=NULL){
        ListNode *newNode=new ListNode(clone->val);
        newNode->next=clone->next;
        clone->next=newNode;
        clone=clone->next->next;
    }
    clone=A;
    while(clone!=NULL){
        clone->next->random=clone->random->next;
        clone=clone->next->next;
    }
    ListNode *original=A, *copy=A->next;
    ListNode *head=copy;
    while (original!=NULL && copy!=NULL){
        if(original->next)
		original->next=original->next->next;
        if(copy->next)
        copy->next=copy->next->next;
        original=original->next;
        copy=copy->next;
    }
   return head;
}