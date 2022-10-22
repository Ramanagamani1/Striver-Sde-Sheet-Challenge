  void markParentNodes(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentArr,TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if(node->left) {
                parentArr[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parentArr[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentArr;
        markParentNodes(root,parentArr,target);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int dist = 0;
        while(!q.empty()) {
            int s = q.size();
            if(dist++ == k) break;
            for(int i=0;i<s;i++) {
                TreeNode *node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(parentArr[node] && !vis[parentArr[node]]) {
                    q.push(parentArr[node]);
                    vis[parentArr[node]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            res.push_back(cur->val);
        }
        return res;
    }