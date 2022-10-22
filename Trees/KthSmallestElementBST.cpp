class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int count = 0;
    int KthSmallestElement(Node *root, int K) {
        if(root==NULL) return -1;
        
        Node *cur = root;
        while(cur!=NULL) {
            if(cur->left==NULL){
                count+=1;
                if(count==K)
                  return cur->data;
                cur=cur->right;
            } else {
                Node *prev = cur->left;
                while(prev->right!=NULL && prev->right!=cur){
                    prev = prev->right;
                }
                if(prev->right==NULL){
                    prev->right = cur;
                    cur=cur->left;
                } else {
                    count++;
                    if(count==K)
                       return cur->data;
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return -1;
    }
};