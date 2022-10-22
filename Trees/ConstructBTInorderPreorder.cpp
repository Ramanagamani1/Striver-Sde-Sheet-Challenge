class Solution {
public:
    TreeNode *buildBinaryTree(vector<int>& pre,int preStart,int preEnd,vector<int>& in,int inStart,int inEnd,map<int,int> &inMap) {
        
        if(preEnd<preStart || inEnd<inStart ) return NULL;
        
        TreeNode* root = new TreeNode(pre[preStart]);
        int inRootInd = inMap[root->val];
        int numleft = inRootInd - inStart;
        
        root->left = buildBinaryTree(pre,preStart+1,preStart+numleft,in,inStart,inRootInd-1,inMap);
        root->right = buildBinaryTree(pre,preStart+numleft+1,preEnd,in,inRootInd+1,inEnd,inMap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]] = i;
        TreeNode *root = buildBinaryTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
};