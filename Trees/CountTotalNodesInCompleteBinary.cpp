int findLeftHeight(TreeNode *root) {
        int height = 0;
        while(root) {
            height++;
            root=root->left;
        }
        return height;
    }
    int findRightHeight(TreeNode *root) {
        int height = 0;
        while(root) {
            height++;
            root=root->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int left = findLeftHeight(root);
        int right = findRightHeight(root);
        
        if(left==right) return (1<<left)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }