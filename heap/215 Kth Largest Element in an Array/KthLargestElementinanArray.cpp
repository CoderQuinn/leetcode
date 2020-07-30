//
//  KthLargestElementinanArray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/24.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace::std;

// using STL
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        for (auto &num : nums) {
            if (min_heap.size() < k) {
                min_heap.push(num);
            } else if (min_heap.top() < num) {
                min_heap.pop();
                min_heap.push(num);
            }
        }
        return min_heap.top();
    }
};

// todo: sort

// todo: heap
