class Solution {
public:
    TreeNode *buildBinaryTree(vector<int>& post,int postStart,int postEnd,vector<int>& in,int inStart,int inEnd,map<int,int> &inMap) {
        
        if(postEnd<postStart || inEnd<inStart ) return NULL;
        
        TreeNode* root = new TreeNode(post[postEnd]);
        int inRootInd = inMap[root->val];
        int numleft = inRootInd - inStart;
        
        root->left = buildBinaryTree(post,postStart,postStart+numleft-1,in,inStart,inRootInd-1,inMap);
        root->right = buildBinaryTree(post,postStart+numleft,postEnd-1,in,inRootInd+1,inEnd,inMap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        int n = inorder.size();
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]] = i;
        TreeNode *root = buildBinaryTree(postorder,0,n-1,inorder,0,n-1,inMap);
        return root;
    }
};