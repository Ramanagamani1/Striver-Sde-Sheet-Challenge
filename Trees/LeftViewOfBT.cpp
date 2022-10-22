void findLeft(Node *root,int level,vector<int> &ans) {
    if(root==NULL) return;
    
    if(level==ans.size())
          ans.push_back(root->data);
    
    if(root->left)
        findLeft(root->left,level+1,ans);
    
    if(root->right)
        findLeft(root->right,level+1,ans);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   findLeft(root,0,ans);
   return ans;
}
