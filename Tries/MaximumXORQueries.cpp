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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>> oq;
    int n=arr.size();
    int q= queries.size();
    for(int i=0;i<q;i++){
        oq.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(oq.begin(),oq.end());
    int ind = 0;
    vector<int> ans(q,0);
    Trie *trie = new Trie();
    for(int i=0;i<q;i++) {
        int ai = oq[i].first;
        int xi = oq[i].second.first;
        int qInd = oq[i].second.second;
        while(ind<n && arr[ind]<=ai){
            trie->insert(arr[ind]);
            ind++;
        }
        if(ind==0)
            ans[qInd]=-1;
        else {
            ans[qInd] = trie->getMax(xi);
        }
    }
    return ans;
}