#include<bits/stdc++.h>
struct Node {
    Node *links[2];

    bool containsKey(int bit) {
        return links[bit]!=NULL;
    }
    
    Node *get(int bit) {
        return links[bit];
    }
    
    void put(int bit,Node *node){
        links[bit] = node;
    }
};
class Trie {
    private : Node *root;
    
    public: 
        Trie() {
            root = new Node();
        }
    
       void insert(int num) {
           Node *curr =  root;
           for(int i=31;i>=0;i--){
               int bit = 1 & (num>>i);
               if(curr->containsKey(bit)!=NULL){
                   curr=curr->get(bit);
               } else {
                   curr->put(bit,new Node());
                   curr=curr->get(bit);
               }
           }
       }
    
       int getMax(int num) {
           Node *curr = root;
           int maxNum = 0;
           for(int i=31;i>=0;i--) {
                 int bit = 1 & (num>>i);
                 if(curr->containsKey(1-bit)){
                      maxNum = maxNum | (1<<i);
                      curr = curr->get(1-bit);
                 } else {
                     curr= curr->get(bit);
                 }
           }
           return maxNum;
       }
};
int maximumXor(vector<int> A)
{
    // Write your code here. 
    Trie *trie = new Trie();
    int maxi =0 ;
    for(int i=0;i<A.size();i++) {
        trie->insert(A[i]);
    }
    for(int i=0;i<A.size();i++){
        maxi = max(maxi,trie->getMax(A[i]));
    }
    return maxi;
}