#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    map<int,vector<int>> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode<int> *node = it.first;
        int ver = it.second;
        mp[ver].push_back(node->data);
        if(node->left){
            q.push({node->left, ver-1});
        } if(node->right) {
            q.push({node->right,ver+1});
        } 
    }
    for(auto it: mp) {
          for(auto x: it.second) {
              ans.push_back(x);
          }
    }
    return ans;
}

/* 
vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode *,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int ver = it.second.first;
            int level = it.second.second;
            
            mp[ver][level].insert(node->val);
            if(node->left) {
                q.push({node->left,{ver-1,level+1}});
            }
            if(node->right) {
                q.push({node->right,{ver+1,level+1}});
            }
        }
        
        for(auto p:mp) {
            vector<int> temp;
            for(auto q:p.second) {
                      temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
*/