//
//  DesignCircularQueue.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/24.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace::std;

class MyCircularQueue1 {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue1(int k) {
        front_ = 0;
        rear_ = 0;
        max_size = k + 1; // 多申请一个空间用来简便操作
        data_vector_ = new std::vector<int>(max_size);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            rear_ = (rear_ + 1) % max_size;
            data_vector_->at(rear_) = value;
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else {
            front_ = (front_ + 1) % max_size;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            int top = (front_ + 1) % max_size;
            return data_vector_->at(top);
        }
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return data_vector_->at(rear_);
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front_ == rear_;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear_ + 1) % max_size == front_;
    }
    
private:
    int front_;
    int rear_;
    int max_size;
    std::vector<int> *data_vector_;
};

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        front_ = -1;
        rear_ = -1;
        size_ = 0;
        capicity_ = k; // 多申请一个空间用来简便操作
        queue_ = new int[capicity_];
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            rear_ = (rear_ + 1) % capicity_;
            queue_[rear_] = value;
            size_++;
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else {
            front_ = (front_ + 1) % capicity_;
            size_--;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return queue_[(front_ + 1) % capicity_];
        }
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return queue_[rear_];
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size_ == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size_ == capicity_;
    }
    
private:
    int front_;
    int rear_;
    int size_;
    int capicity_;
    int *queue_;
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
