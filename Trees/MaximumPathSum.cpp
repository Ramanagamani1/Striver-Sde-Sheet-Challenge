int findMaxPath(TreeNode *root,int &maxi) {
        if(root==NULL) return 0;
        
        int leftsum = findMaxPath(root->left,maxi);
        int rightsum = findMaxPath(root->right,maxi);
        if(leftsum<0) leftsum = 0;
        if(rightsum<0) rightsum = 0;
        maxi = max(maxi,root->val+leftsum+rightsum);
        return root->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        findMaxPath(root,maxi);
        return maxi;
    }