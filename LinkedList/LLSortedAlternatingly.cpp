//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
Node *reverse(Node *head) {
    Node *curr = head, *prev=NULL, *next = NULL;
         
         while(curr!=NULL) {
             
             next = curr->next;
             curr->next = prev;
             prev = curr;
             curr = next;
         }
         
         return prev;
}

void sort(Node **head)
{
    if(*head == NULL) 
        return ;
        
    Node *temp = *head;
    Node *even = NULL , *odd = NULL;
    Node *ee = NULL, *oe = NULL;

    int count = 1;
    
    if(temp->next == NULL) {
        return;
    }

    while(temp!=NULL) {

       if(count%2==0) {

            if(even==NULL) {
                    even = ee = temp;
                } else {
                    ee->next = temp;
                    ee = ee->next;
                }
            } else {

                if(odd==NULL) {
                    odd = oe = temp;
                }
                else {
                    oe->next = temp;
                    oe = oe->next;
                }
            }
            count+=1;
            temp = temp->next;     
     }
     
     oe->next = NULL;
     ee->next = NULL;
     
     even = reverse(even);
     
     Node *dummy = new Node(-1);
     temp = dummy;
     
     while(odd!=NULL && even!=NULL) {
         
         if(even->data <=  odd->data) {
             temp->next = even;
             even = even->next;
         }
         else {
             temp->next = odd;
             odd = odd->next;
         }
         temp = temp->next;
     }
     
     if(odd!=NULL) {
         temp->next = odd;
     }
     if(even!=NULL) {
         temp->next = even;
     }
     
     *head = dummy->next;
}