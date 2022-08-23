/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node {
    Node *child[26];
    bool isEnd = false;
    
    bool containsKey(char ch) {
        return (child[ch-'a']!=NULL);
    }
    
    void put(char ch, Node *node) {
        child[ch-'a'] = node;
    }
    
    Node *get(char ch) {
        return child[ch-'a'];
    }
    
    void setEnd() {
        isEnd = true;
    }
    
};

class Trie {
private: Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
       root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = root;
        for(int i=0;i<word.length();i++) {
            if(!curr->containsKey(word[i])) {
                curr->put(word[i],new Node());
            }
            curr = curr->get(word[i]);
        }
        curr->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        for(int i=0;i<word.length();i++) {
            if(curr->containsKey(word[i])) {
                 curr = curr->get(word[i]);
            }
            else
                return false;
        }
        return curr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
          Node *curr = root;
          for(int i=0;i<word.length();i++) {
             if(!curr->containsKey(word[i])) {
                 return false;
             }
              curr = curr->get(word[i]);
         }
        return true;
    }
};