void postorderTraversal(Node *root,vector<int> &ans) {
        if(root==NULL)
           return ;
           
        postorderTraversal(root->left,ans);
        postorderTraversal(root->right,ans);
        ans.push_back(root->data);
    }

vector <int> postOrder(Node* root)
{
   vector<int> ans;
        postorderTraversal(root,ans);
        return ans;
}
