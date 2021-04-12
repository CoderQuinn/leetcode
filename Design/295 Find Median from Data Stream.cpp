//
//  295 Find Median from Data Stream.cpp
//  Leetcode
//
//  Created by Quinn on 2021/4/8.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> down;
    priority_queue<int, vector<int>, greater<int>> up;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if(down.empty() || num <= down.top())
        {
            down.push(num);
            if(down.size() > up.size() + 1)
            {
                up.push(down.top());
                down.pop();
            }
        }
        else
        {
            up.push(num);
            if(up.size() > down.size())
            {
                down.push(up.top());
                up.pop();
            }
        }
    }
    
    double findMedian() {
        if((up.size() + down.size()) % 2) return down.top();
        else return (up.top() + down.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
