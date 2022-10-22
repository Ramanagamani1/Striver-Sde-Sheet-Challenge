class BSTIterator {
    private :
       stack<TreeNode*> st;
       bool reverse = true; 
       // reverse=true; ->before() , reverse=false; ->next()
    public:
    
         BSTIterator(TreeNode *root,bool isReverse) {
             reverse = isReverse;
             pushAll(root);
         }
    
         void pushAll(TreeNode *root){
             while(root!=NULL) {
                 st.push(root);
                 if(reverse)
                     root=root->right;
                 else
                     root=root->left;
             }
         }
         
         bool hasNext(){
             return !st.empty();
         }
    
         int next() {
             TreeNode *node = st.top();
             st.pop();
             if(reverse)
                 pushAll(node->left);
             else
                 pushAll(node->right);
             return node->val;
         }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
          if(root==NULL) return false;
          
           BSTIterator l(root,false); //next
           BSTIterator r(root,true); // before
        
           int i = l.next();
           int j = r.next();
        
           while(i<j) {
               if(i+j==k) return true;
               else if(i+j<k)
                   i=l.next();
               else
                   j=r.next();
           }
        return false;
    }
};