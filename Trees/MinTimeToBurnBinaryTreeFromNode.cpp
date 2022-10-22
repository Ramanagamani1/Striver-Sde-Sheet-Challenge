int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> parentArr;
       Node * tar;
       queue<Node*> q;
       q.push(root);
        while(!q.empty()) {
            Node *node = q.front();
            q.pop();
            if(node->left) {
                parentArr[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parentArr[node->right] = node;
                q.push(node->right);
            }
            if(node->data == target)
                tar=node;
        }
        unordered_map<Node*,bool> vis;
        q.push(tar);
        vis[tar] = true;
        int dist = 0;
        while(!q.empty()) {
            int s = q.size();
            int flag = 0;
            for(int i=0;i<s;i++) {
                Node *node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    flag=1;
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]) {
                    q.push(node->right);
                    flag=1;
                    vis[node->right] = true;
                }
                if(parentArr[node] && !vis[parentArr[node]]) {
                    q.push(parentArr[node]);
                    flag=1;
                    vis[parentArr[node]] = true;
                }
            }
            if(flag) dist++;
        }
        return dist;
    }
};