//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
         Node *curr = head, *prev=NULL, *next = NULL;
         
         while(curr!=NULL) {
             
             next = curr->next;
             curr->next = prev;
             prev = curr;
             curr = next;
         }
         
         return prev;
    }
    
    Node* addOne(Node *head) 
    {
        Node *rev = reverseList(head);
        Node *temp = rev;
        Node *prev = NULL;
        
        int carry = 1;
        
        while(temp!=NULL && carry!=0) {
            
            int s = temp->data+carry;
            temp->data = s%10;
            carry = s/10;
            prev = temp;
            temp = temp->next;
        }
        
        if(carry!=0) {
            prev->next = new Node(carry);
        }
        
        return reverseList(rev);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends