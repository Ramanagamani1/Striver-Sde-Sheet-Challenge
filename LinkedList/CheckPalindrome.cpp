//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverseList(Node *head) {
        if(head==NULL || head->next==NULL)
           return head;
        Node *newNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newNode;
    }
    bool isPalindrome(Node *head)
    {
        if(head==NULL) return true;
        Node *slow = head, *fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL) {
              slow = slow->next;
              fast=fast->next->next;
        }
         
        Node *rev = reverseList(slow->next);
        Node *temp = head;
        
        while(rev!=NULL) {
            if(rev->data!=temp->data) {
                return false;
            }
            rev = rev->next;
            temp = temp->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends