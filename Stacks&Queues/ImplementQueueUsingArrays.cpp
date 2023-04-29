#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int front1, rear1;
    
public:
    Queue() {
        // Implement the Constructor
        arr = new int[100000];
        front1 = 0, rear1 = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(front1==rear1 || rear1==0)
           return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[rear1] = data;
        rear1++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(front1==rear1)
           return -1;
        int x = arr[front1];
        front1++;
        return x;
    }

    int front() {
        // Implement the front() function

        if(front1==rear1)
           return -1;
        return arr[front1];

    }
};