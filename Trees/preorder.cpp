void preorderTraversal(Node *root,vector<int> &ans) {
        if(root==NULL)
           return ;
           ans.push_back(root->data);
        preorderTraversal(root->left,ans);
        
        preorderTraversal(root->right,ans);
    }

vector <int> preorder(Node* root)
{
  // Your code here
   vector<int> ans;
        preorderTraversal(root,ans);
        return ans;
}