#include<bits/stdc++.h>
class LRUCache
{
public:
    class node {
        public:
        int key,val;
        node *next, *prev;

        node(int key_,int val_) {
            key = key_;
            val = val_;
        }

    };

    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        tail->prev = head;
        head->next = tail;
    }

    void addNode(node *newnode) {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(node *delNode) {
        node *delprev = delNode->prev;
        node *delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        if(mp.find(key)!=mp.end()) {

            node *resnode = mp[key];
            int res = resnode->val;
            mp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end()) {
            node *existingnode = mp[key];
            mp.erase(key);
            deleteNode(existingnode);
        }
        if(mp.size()==cap) {

            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        mp[key] = head->next;
    }
};
