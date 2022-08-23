#include<bits/stdc++.h>
struct Node {
    Node *child[26];
    bool isEnd = false;
    
    bool containsKey(char ch){
        return child[ch-'a']!=NULL;
    }
    
    Node *get(char ch) {
        return child[ch-'a'];
    }
    
    void put(char ch, Node *node) {
        child[ch-'a'] = node;
    }
    
    void setEnd() {
        isEnd= true;
    }
    
    bool isEnded() {
        return isEnd;
    }
};

class Trie {
    private: Node *root;
    public :
    
    Trie() {
        root =  new Node();
    };
    
    void insert(string &word) {
        Node *curr= root;
        for(int i=0;i<word.length();i++) {
            if(!curr->containsKey(word[i]))
                curr->put(word[i],new Node());
            curr = curr->get(word[i]);
        }
        curr->setEnd();
    }  
    
    bool checkPrefixExists(string &word) {
        Node *curr = root;
        bool flag = true;
        for(int i=0;i<word.length();i++) {
            if(curr->containsKey(word[i])) {
                 curr = curr->get(word[i]);
                 flag = flag & curr->isEnded();
            } 
            else 
            return false;
        }
        return flag;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie *trie = new Trie();
    for(auto &it: a ) {
        trie->insert(it);
    }
    string longest= "";
    for(auto &it:a) {
        if(trie->checkPrefixExists(it)){
            if(it.length() > longest.length()) {
                longest = it;
            } else if(it.length()== longest.length() && it<longest) {
                longest = it;
            }
        }
    }
    if(longest == "") return "None";
    return longest;
}