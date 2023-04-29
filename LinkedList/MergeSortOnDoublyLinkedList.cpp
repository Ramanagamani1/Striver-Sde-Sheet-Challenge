//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


// } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


//Function to sort the given doubly linked list using Merge Sort.
Node *merge(Node *head1, Node *head2) {
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        
        Node *temp1 = head1, *temp2 = head2;
        
        while(temp1!=NULL && temp2!=NULL) {
            
            if(temp1->data<=temp2->data) {
                
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
                temp1 = temp1->next;
            }
            else {
                
                temp->next = temp2;
                temp2->prev = temp;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        if(temp1!=NULL) {
            temp1->prev = temp;
            temp->next = temp1;
        }
        if(temp2!=NULL) {
            temp2->prev = temp;
            temp->next = temp2;
        }
        dummy->next->prev = NULL;
        return dummy->next;
}

Node *middleNode(Node *head) {
        
        Node *slow = head, *fast= head;
        
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
 }
    
struct Node *sortDoubly(struct Node *head)
{
	   if(head==NULL || head->next==NULL)
	       return head;
	       
	   Node *middle = middleNode(head);
	   Node *left , *right;
	   
	   left = head;
	   right = middle->next;
	   
	   middle->next = NULL;
	   right->prev = NULL;
	   
	   left = sortDoubly(left);
	   right = sortDoubly(right);
	   
	   Node *ans = merge(left,right);
	   
	   return ans;
}


//{ Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}

// } Driver Code Ends