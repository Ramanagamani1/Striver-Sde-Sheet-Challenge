#include<stack>
class Queue {
    // Define the data members(if any) here.
    

    public:
    stack<int> s1;
    stack<int> s2;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
         s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        int x;
        if(s1.empty() && s2.empty())
          return -1;
        if(!s2.empty()) {
           x = s2.top();
           s2.pop();
           return x;
        } else {

            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
           x = s2.top();
           s2.pop();
           return x;
        }
    }

    int peek() {
        // Implement the peek() function here.
        int x;
        if(s1.empty() && s2.empty())
          return -1;
        if(!s2.empty()) {
           x = s2.top();
           return x;
        } else {

            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
           x = s2.top();
           return x;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
         if(s1.empty() && s2.empty())
          return true;
        return false;
    }
};