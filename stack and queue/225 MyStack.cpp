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

// 思路：主栈只负责出入，辅助栈只负责移动位置
class MyStack {
public:
    queue<int> *q1; // 出入队列
    queue<int> *q2; // 辅助队列
    
    /** Initialize your data structure here. */
    MyStack() {
        q1 = new queue<int>();
        q2 = new queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = top();
        q1->pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        if(q1->empty()) {
            auto tmp = q1;
            q1 = q2;
            q2 = tmp;
        }
        
        while(q1->size() > 1) {
            int val = q1->front();
            q1->pop();
            q2->push(val);
        }
        
        return q1->front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1->empty() && q2->empty();
    }
};
