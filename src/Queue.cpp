#include "../include/Queue.h"

Queue::Queue() : frontIndex(0), rearIndex(-1), count(0) {}

void Queue::enqueue(int item) {
    if (isFull()) {
        throw std::overflow_error("Queue is full");
    }
    rearIndex = (rearIndex + 1) % CAP;
    data[rearIndex] = item;
    count++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    int item = data[frontIndex];
    frontIndex = (frontIndex + 1) % CAP;
    count--;
    return item;
}

int Queue::front() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return data[frontIndex];
}

int Queue::peek() const {
    return front();
}

bool Queue::isEmpty() const {
    return count == 0;
}

bool Queue::isFull() const {
    return count == CAP;
}

int Queue::size() const {
    return count;
}

void Queue::clear() {
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}