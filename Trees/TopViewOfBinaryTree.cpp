vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int ver = it.second;
            
            if(mp.find(ver)==mp.end())  
              mp[ver] = node->data;
              
            if(node->left!=NULL)
               q.push({node->left,ver-1});
               
            if(node->right!=NULL) 
              q.push({node->right,ver+1});
        }
        
        for(auto it:mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }