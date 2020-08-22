//
//  FindMedianFromDataStream.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/24.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace::std;

/*
算法：

两个优先级队列：
用于存储较小一半数字的最大堆 lo
用于存储较大一半数字的最小堆 hi
最大堆 lo 允许存储的元素最多比最小堆 hi 多一个。因此，如果我们处理了 k 元素：
如果 k=2*n+1 \quad(\forall,n \in \mathbb z)k=2∗n+1(∀,n∈z) 则允许 lo 持有 n+1 元素，而 hi 可以持有 n 元素。
如果 k=2*n\quad(\forall,n\in\mathbb z)k=2∗n(∀,n∈z)，那么两个堆都是平衡的，并且每个堆都包含 n 个元素。
这给了我们一个很好的特性，即当堆完全平衡时，中间值可以从两个堆的顶部派生。否则，最大堆 lo 的顶部保留合法的中间值。

添加一个数 num：
将 num 添加到最大堆 lo。因为 lo 收到了一个新元素，所以我们必须为 hi 做一个平衡步骤。因此，从 lo 中移除最大的元素并将其提供给 hi。
在上一个操作之后，最小堆 hi 可能会比最大堆 lo 保留更多的元素。我们通过从 hi 中去掉最小的元素并将其提供给 lo 来解决这个问题。
上面的步骤确保两个堆能够平衡

*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        max_heap_.push(num);
        
        min_heap_.push(max_heap_.top());
        max_heap_.pop();
        
        if (max_heap_.size() < min_heap_.size()) {
            max_heap_.push(min_heap_.top());
            min_heap_.pop();
        }
    }
    
    double findMedian() {
        if (max_heap_.size() == min_heap_.size()) {
            return (max_heap_.top() + min_heap_.top()) / 2.0;
        } else {
            return max_heap_.top();
        }
    }
private:
    std::priority_queue<int> max_heap_;
    std::priority_queue<int, vector<int>, greater<int>> min_heap_;
};

