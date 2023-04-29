class LRUCache {
public:
    class Node {
     public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int key,int val) {
            this->key = key;
            this->val = val;
        }
    };
    int cap;
    unordered_map<int,Node*> mp;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deletenode(Node *delnode) {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    void addnode(Node *newNode) {
        Node *temp= head->next;
        newNode -> next = temp;
        newNode -> prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()) {
              Node *resnode = mp[key];
              int res = resnode->val;
              mp.erase(key);
              deletenode(resnode);
              addnode(resnode);
              mp[key] = head->next;
              return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
         if(mp.find(key)!=mp.end()) {
              Node *existingnode = mp[key];
              mp.erase(key);
              deletenode(existingnode);
         }
         if(mp.size()==cap) {
              mp.erase(tail->prev->key);
              deletenode(tail->prev);
         }
         addnode(new Node(key,value));
         mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */