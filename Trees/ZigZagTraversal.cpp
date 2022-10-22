vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()) {
            int s= q.size();
            vector<int> level;
            for(int i=0;i<s;i++) {
                TreeNode *node = q.front();
                q.pop();
                
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                level.push_back(node->val);
            }
            if(flag)
                reverse(level.begin(),level.end());
                ans.push_back(level);
            flag = !flag;
        }
        return ans;
    }