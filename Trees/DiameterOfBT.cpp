int findMax(Node *root,int &maxi) {
        if(root==NULL) return 0;
        
        int lh = findMax(root->left,maxi);
        int rh = findMax(root->right,maxi);
        
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    int diameter(Node* root) {
       int maxi = -1e9;
       findMax(root,maxi);
       return maxi+1;
    }