//
//  MyStack.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/18.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace::std;

/*
 使用队列实现栈的下列操作：

 push(x) -- 元素 x 入栈
 pop() -- 移除栈顶元素
 top() -- 获取栈顶元素
 empty() -- 返回栈是否为空
 注意:

 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

 */
// 思路：栈1只负责入，栈2只负责出
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        queue1 = new std::queue<int>();
        queue2 = new std::queue<int>();
    }
    
    ~MyStack() {
        delete queue1;
        delete queue2;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue1->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int element = top();
        queue1->pop();
        return element;
    }
    
    /** Get the top element. */
    int top() {
        if (queue1->empty()) { // 此时将队列2作为出入队列，节省操作
            std::queue<int> *temp = queue1;
            queue1 = queue2;
            queue2 = temp;
        }
        
        while (queue1->size() > 1) {
            int element = queue1->front();
            queue1->pop();
            queue2->push(element);
        }
        int element = queue1->front();
        return element;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1->empty() && queue2->empty();
    }
    
private:
    std::queue<int> *queue1; // 出入队列
    std::queue<int> *queue2; // 辅助队列，用于调整顺序
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
