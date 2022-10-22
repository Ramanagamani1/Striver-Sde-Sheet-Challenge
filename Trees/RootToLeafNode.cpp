void findPaths(Node *root,vector<int> ds,vector<vector<int>> &ans) {
      ds.push_back(root->data);
      if(root->left==NULL && root->right==NULL) 
      {
          ans.push_back(ds);
          return ;
      }
      if(root->left!=NULL)
          findPaths(root->left,ds,ans);
      if(root->right!=NULL) 
          findPaths(root->right,ds,ans);
      ds.pop_back();
       
}
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    vector<int> ds;
    if(root==NULL) return ans;
    findPaths(root,ds,ans);
    return ans;
}
