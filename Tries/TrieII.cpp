struct Node {
    Node *child[26];
    int endWith = 0;
    int countPrefix = 0;
    
    bool containsKey(char ch) {
        return child[ch-'a']!=NULL;
    }
    
    Node *get(char ch) {
        return child[ch-'a'];
    }
    
    void put(char ch, Node *node){
        child[ch-'a'] = node;
    }
    
    void increaseEnd() {
        endWith++;
    }
    
    void deleteEnd() {
         endWith--;
    }
    
    void increasePrefix() {
        countPrefix++;
    }
    
    void reducePrefix() {
        countPrefix--;
    }
    
    int getEnd() {
        return endWith;
    }
    
    int getPrefix() {
        return countPrefix;
    }
};
class Trie{
    private: Node *root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *node = root;
        for(int i=0;i<word.length();i++) {
             if(!node->containsKey(word[i])) {
                 node->put(word[i],new Node);
             }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *curr = root;
        for(int i=0;i<word.length();i++) {
            if(!curr->containsKey(word[i])){
                return 0;
            } else {
                 curr = curr->get(word[i]);
            }   
        }
        return curr->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *curr = root;
        for(int i=0;i<word.length();i++) {
            if(!curr->containsKey(word[i])){
                return 0;
            } else {
                 curr = curr->get(word[i]);
            }   
        }
        return curr->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node *curr = root;
        for(int i=0;i<word.length();i++) {
            if(curr->containsKey(word[i])){
                 curr = curr->get(word[i]);
                 curr->reducePrefix();
            } else {
                return ;
            }
        }
        curr->deleteEnd();
    }
};
