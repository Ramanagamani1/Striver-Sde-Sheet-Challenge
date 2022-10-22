bool search(Node* root, int x) {
    // Your code here
    while(root!=NULL && root->data!=x){
        root = root->data>x ? root->left : root->right;
    }
    if(root==NULL)
      return false;
    else
      return true;
}
