vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        
        if(root==NULL) return ans;
        
        while(!s1.empty()) {
            TreeNode *node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left!=NULL) {
                 s1.push(node->left);
            }
            if(node->right!=NULL) {
                s1.push(node->right);
            }
        }
        
        while(!s2.empty()) {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }

/*Using one stack */

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        if(root==NULL) return ans;
        
        while(cur!=NULL || !st.empty()) {
            if(cur!=NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode *temp = st.top()->right;
                if(temp==NULL) {
                     temp=st.top();
                     st.pop();
                     ans.push_back(temp->val);
                     while(!st.empty() && temp==st.top()->right) {
                         temp = st.top();
                         st.pop();
                         ans.push_back(temp->val);
                     }
                } else {
                    cur = temp;
                }
            }
        }
        return ans;
    }