#include<bits/stdc++.h>
struct Node {
    Node *child[26];
    
    bool containsKey(char ch){
        return child[ch-'a']!=NULL;
    }
    Node *get(char ch) {
        return child[ch-'a'];
    }
    void put(char ch, Node *node) {
        child[ch-'a'] = node;
    }
    
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int count = 0;
    Node *root = new Node();
    for(int i=0;i<s.size();i++) {
        Node *curr = root;
        for(int j=i;j<s.size();j++) {
            if(!curr->containsKey(s[j])) {
                curr->put(s[j],new Node());
                count+=1;
             }
             curr = curr->get(s[j]);
        }
    }
    return count+1;
}