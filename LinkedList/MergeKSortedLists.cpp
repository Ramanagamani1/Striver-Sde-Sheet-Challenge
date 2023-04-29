//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node *merge(Node *head1, Node *head2) {
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        
        Node *temp1 = head1, *temp2 = head2;
        
        while(temp1!=NULL && temp2!=NULL) {
            
            if(temp1->data<=temp2->data) {
                
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
            }
            else {
                
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        if(temp1!=NULL) {
            temp->next = temp1;
        }
        if(temp2!=NULL) {
            temp->next = temp2;
        }
        return dummy->next;
    }
    
    Node * mergeKLists(Node *arr[], int K)
    {
          Node *head = arr[0];
          
          for(int i=1;i<K;i++) {
              
              Node *temp = arr[i];
              head = merge(head,temp);
          }
          
          return head;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends