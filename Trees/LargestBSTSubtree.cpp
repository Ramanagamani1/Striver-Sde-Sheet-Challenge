class NodeValue {
    public:
    int minNode, maxNode,size;
    
    NodeValue(int minNode,int maxNode,int size) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->size = size;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue largestBstHelper(Node *root) {
        if(root==NULL) {
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        auto left = largestBstHelper(root->left);
        auto right = largestBstHelper(root->right);
        
        if(left.maxNode < root->data && root->data<right.minNode) {
            return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.size+right.size+1);
        }
        
        return NodeValue(INT_MIN,INT_MAX,max(left.size,right.size));
    }
    int largestBst(Node *root)
    {
    	return largestBstHelper(root).size;
    }
};