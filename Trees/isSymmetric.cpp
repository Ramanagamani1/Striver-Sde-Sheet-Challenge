 bool checkIsSymmetric(TreeNode *root1,TreeNode *root2) {
        if(root1==NULL || root2==NULL)
            return (root1==root2);
        return (root1->val==root2->val) && checkIsSymmetric(root1->left,root2->right)
                     && checkIsSymmetric(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
	    return checkIsSymmetric(root->left,root->right);
    }