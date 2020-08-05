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
// 思路：主栈只负责出入，辅助栈只负责移动位置
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
        main_queue = new queue<int>();
        help_queue = new queue<int>();
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        main_queue->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int val = top();
        main_queue->pop();
        return val;
    }

    /** Get the top element. */
    int top()
    {
        if (main_queue->empty())
        {
            std::queue<int> *tmp = main_queue;
            main_queue = help_queue;
            help_queue = tmp;
        }

        while (main_queue->size() > 1)
        {
            int val = main_queue->front();
            main_queue->pop();
            help_queue->push(val);
        }
        return main_queue->front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return main_queue->empty() && help_queue->empty();
    }

private:
    std::queue<int> *main_queue; // 出入栈
    std::queue<int> *help_queue; // 辅助栈
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
