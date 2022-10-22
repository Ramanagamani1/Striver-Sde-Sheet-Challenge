ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *p1=A,*p2=B;
    ListNode *headNode=NULL,*tailNode=NULL;
    if(p1->val<p2->val){
        headNode=p1;
        tailNode=p1;
        p1=p1->next;
    }
    else{
        headNode=p2;
        tailNode=p2;
        p2=p2->next;
    }
    while(p1!=NULL && p2!=NULL){
        if(p1->val<p2->val){
            tailNode->next=p1;
            tailNode=p1;
            p1=p1->next;
        }
        else{
            tailNode->next=p2;
            tailNode=p2;
            p2=p2->next;
        }
    }
    if(p1!=NULL){
       tailNode->next=p1;
            tailNode=p1;
    }
    if(p2!=NULL){
        tailNode->next=p2;
        tailNode=p2;
    }
    A=headNode;
    return A;
}

/* or */

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        if(list1->val> list2->val){
            swap(list1,list2);
        }
        ListNode *res = list1;
        
        while(list1!=NULL && list2!=NULL) {
            ListNode *temp = NULL;
            while(list1!=NULL && list1->val<=list2->val) {
                temp=list1;
                list1=list1->next;
            }
            temp->next = list2;
            swap(list1,list2);
        }
        return res;
    }