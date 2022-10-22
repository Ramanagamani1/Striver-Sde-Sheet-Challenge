void solve(TreeNode<int>* root, int k,int &ans,int &i) {
    if(root==NULL) return ;
    solve(root->right,k,ans,i);
    i+=1;
    if(i==k){
        ans = root->data;
        return ;
    }
    solve(root->left,k,ans,i);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int ans = -1,i=0;
    solve(root,k,ans,i);
    return ans;
}
