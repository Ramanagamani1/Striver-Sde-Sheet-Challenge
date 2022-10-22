int findCeil(Node* root, int input) {
    int ceil = -1;
    while(root!=NULL) {
        if(root->data==input) {
            return root->data;
        }
        if(root->data>input) {
            ceil = root->data;
            root=root->left;
        } else {
            root=root->right;
        }
    }
    return ceil;
    // Your code here
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int floor = -1;
    while(root!=NULL) {
        if(root->val==X) {
            return root->val;
        }
        if(root->val>X) {
            root=root->left;
        } else {
            floor = root->val;
            root=root->right;
        }
    }
    return floor;
}