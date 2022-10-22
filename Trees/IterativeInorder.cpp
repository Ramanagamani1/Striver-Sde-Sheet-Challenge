vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty()) {
               while(root!=NULL) {
                   st.push(root);
                   root=root->left;
               }
               root = st.top();
               st.pop();
               ans.push_back(root->val);
               root = root->right;
        }
        return ans;
    }
