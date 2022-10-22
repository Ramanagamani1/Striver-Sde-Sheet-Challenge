void findRight(TreeNode *root,int level,vector<int> &ans) {
    if(root==NULL) return;
    
    if(level==ans.size())
          ans.push_back(root->val);
        
    if(root->right)
        findRight(root->right,level+1,ans);
    
    if(root->left)
        findRight(root->left,level+1,ans);  
    
   }
    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
       findRight(root,0,ans);
       return ans;
    }