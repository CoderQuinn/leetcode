//
//  232 Implement Queue using Stacks.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> q1; // 入栈
    stack<int> q2; // 出栈

    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        q1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int val = peek();
        q2.pop();
        return val;
    }

    /** Get the front element. */
    int peek()
    {
        if (q2.empty())
        {
            while (!q1.empty())
            {
                q2.push(q1.top());
                q1.pop();
            }
        }

        return q2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
