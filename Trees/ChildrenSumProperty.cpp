 int isSumProperty(Node *root)
    {
     // Add your code here
         if(root==NULL)
             return 1;
        
         if(root->left==NULL && root->right==NULL)
                return 1;
         
         int leftsum = 0;
         int rightsum = 0;
         
         if(root->left)
           leftsum = root->left->data;
           
         if(root->right)
            rightsum = root->right->data;
            
         if(root->data == leftsum+rightsum && isSumProperty(root->left) && isSumProperty(root->right))
              return 1;
         return 0;
    }

/*
 bool ans = true;
    int isSum(Node *root) {
        if(!root)
             return 0;
             
        if(!root->left && !root->right)
                return root->data;
         
         int leftsum = isSum(root->left);
         int rightsum = isSum(root->right);
         
         int sum = leftsum+rightsum;
         if(root->data!=sum)
               ans=false;
               
         return root->data;
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
         if(root==NULL)
             return 0;
        
         isSum(root);
         
         return ans;
    }

/* Change Binary Tree */

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL) return ;
    int child = 0;
    if(root->left)
         child+=root->left->data;
    if(root->right)
        child+=root->right->data;
    if(child >= root->data)
        root->data = child;
    else {
        if(root->left) root->left->data= root->data;
        if(root->right) root->right->data = root->data;
     }
     changeTree(root->left);
     changeTree(root->right);
    
     int total = 0;
     if(root->left) 
         total+= root->left->data;
    if(root->right)
        total+= root->right->data;
    if(root->left || root->right) root->data = total;
}  
*/