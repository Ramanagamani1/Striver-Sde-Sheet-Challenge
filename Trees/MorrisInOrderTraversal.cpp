  vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root;
        while(cur!=NULL) {
            if(cur->left==NULL) {
                ans.push_back(cur->val);
                cur=cur->right;
            } else {
                TreeNode *prev = cur->left;
                //find the right most guy from the left sub tree
                while(prev->right && prev->right!=cur) {
                    prev=prev->right;
                }
                if(prev->right==NULL) {
                    prev->right=cur;
                    cur=cur->left;
                } else {
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }