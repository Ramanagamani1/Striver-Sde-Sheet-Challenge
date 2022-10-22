class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node *build(int pre[],int &i,int size, int bound) {
        if(pre[i]>bound || i==size) return NULL;
        
        Node *root = newNode(pre[i++]);
        root->left = build(pre,i,size,root->data);
        root->right = build(pre,i,size,bound);
        
        return root;
    }
    Node* post_order(int pre[], int size)
    {
        int i=0;
        return build(pre,i,size,INT_MAX);
    }
};