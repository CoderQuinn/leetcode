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

// 对顶堆
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    priority_queue<int> max_heap;                            // 左边
    priority_queue<int, vector<int>, greater<int>> min_heap; // 右边
    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top())
        {
            max_heap.push(num);
            while (max_heap.size() - min_heap.size() > 1)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
        else
        {
            min_heap.push(num);
            while (max_heap.size() < min_heap.size())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }
    
    double findMedian() {
        auto sum = max_heap.size() + min_heap.size();
        if (sum % 2)
        {
            return max_heap.top();
        }
        else
        {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }
};

