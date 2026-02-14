#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

class Queue {
private:
    static const int CAP = 10;
    int data[CAP];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue();
    void enqueue(int item);
    int dequeue();
    int front() const;
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void clear();
};

#endif