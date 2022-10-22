int check(Node *root) {
        if(root==NULL) return 0;
        
        int lh = check(root->left);
        int rh = check(root->right);
        
        if(lh==-1 || rh ==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        
        return max(lh,rh)+1;
        
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return check(root)!=-1;
    }