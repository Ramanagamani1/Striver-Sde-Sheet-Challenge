/* Recursive */

class Solution {
     TreeNode *prev = NULL;
public:
   
    void flatten(TreeNode* root) {
            if(root==NULL) return;
            flatten(root->right);
            flatten(root->left);
            
            root->right = prev;
            root->left=NULL;
            
            prev=root;
    }
};

/*Iterative using stack */

void flatten(Node *root)
    {
        //code here
        stack<Node *> st;
        st.push(root);
        while(!st.empty()) {
            Node *cur = st.top();
            st.pop();
            
            if(cur->right)
                  st.push(cur->right);
            if(cur->left)
               st.push(cur->left);
               
            if(!st.empty()) {
                cur->right = st.top();
            }
            cur->left=NULL;
        }
       
    }

/* Iterative without stack */

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *cur = root;
    while(cur!=NULL) {
        if(cur->left!=NULL) {
            TreeNode<int> * temp = cur->left;
            while(temp->right!=NULL)
                temp=temp->right;
            temp->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
    return root;
}