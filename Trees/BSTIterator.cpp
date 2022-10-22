class BSTIterator {
    private:
       stack<TreeNode *> st;
public:
    void pushAll(TreeNode* root) {
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();
        int ans = node->val;
        node = node->right;
        pushAll(node);
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
