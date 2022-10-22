bool validateBST(Node *root,int mini,int maxi) {
        if(root==NULL) return true;
        
        if(root->data>=maxi || root->data<=mini) return false;
        
        return validateBST(root->left,mini,root->data)&& validateBST(root->right,root->data,maxi);
    }
    bool isBST(Node* root) 
    {
        return validateBST(root,INT_MIN,INT_MAX);
    }