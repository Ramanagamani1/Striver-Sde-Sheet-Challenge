#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void findPredecessor(BinaryTreeNode<int>*root, int &pre,int key) {
    while(root!=NULL){
        if(root->data >= key) {
           root=root->left;
        } else {
            pre = root->data;
            root = root->right;
        }
    }
}
void findSuccessor(BinaryTreeNode<int> *root, int &suc,int key) {
       while(root!=NULL) {
            if(root->data > key) {
                suc=root->data;
                root=root->left;
            } else {
                root=root->right;
             }
       }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    if(root==NULL) return {-1,-1};
    int pre = -1,suc=-1;
    findPredecessor(root,pre,key);
    findSuccessor(root,suc,key);
    return {pre,suc};
}
