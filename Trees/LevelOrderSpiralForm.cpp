struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
      vector<int> ans;
      if(root==NULL) return ans;
      queue<Node*> q;
      q.push(root);
      bool flag=true;
      while(!q.empty()) {
          int s = q.size();
          vector<int> level;
          for(int i=0;i<s;i++) {
               Node *node = q.front();
               q.pop();
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                level.push_back(node->data);
          }
          if(flag) {
              reverse(level.begin(),level.end());
          }
          flag = !flag;
          for(int i=0;i<level.size();i++)
              ans.push_back(level[i]);
          
      }
      return ans;
}