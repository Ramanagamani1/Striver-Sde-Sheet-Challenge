class Solution {
public:
    TreeNode *findRight(TreeNode *root) {
        if(root->right==NULL)
            return root;
        return findRight(root->right);
    }
    TreeNode *helper(TreeNode *root) {
        if(root->left==NULL)
            return root->right;
        if(root->right==NULL)
            return root->left;
        TreeNode *rightchild = root->right;
        TreeNode *lastRight = findRight(root->left);
        lastRight->right = rightchild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        
        if(root->val==key) {
            return helper(root);
        }
        TreeNode *cur = root;
        while(root!=NULL) {
            if(root->val>key) {
                if(root->left!=NULL && root->left->val==key){
                    root->left = helper(root->left);
                    break;
                } else {
                    root=root->left;
                }
            } else {
                if(root->right!=NULL && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                } else {
                    root=root->right;
                }
            }
        }
        return cur;
    }
};

or

public static Node deleteNode(Node root, int x) {

        // code here.

        if(root==null)

        return root;

        //case 1

        if(root.data>x){

            root.left=deleteNode(root.left,x);

        }

        else if(root.data<x){

             root.right=deleteNode(root.right,x);

        }

        else{

            //when either root left or right is null

            //case 2

            if(root.left==null)

            return root.right;

            else if(root.right==null)

            return root.left;

            //case 3

            root.data=minval(root.right);

            root.right=deleteNode(root.right,root.data);

        }

        return root;

    }

    public static int minval(Node root){

        int minval=root.data;

        while(root.left!=null){

            minval=root.left.data;

            root=root.left;

        }

        return minval;

    }

 