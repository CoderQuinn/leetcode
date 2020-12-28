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

// using STL heap
class Solution0 {
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

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quick_select(nums, 0, nums.size() - 1, k - 1);
    }

    int quick_select(vector<int> &nums, int l, int r, int k)
    {
        if (l == r)
            return nums[k];
        int x = nums[l], i = l - 1, j = r + 1;

        while (i < j)
        {
            while (nums[++i] > x)
                ;
            while (nums[--j] < x)
                ;

            if (i < j)
                swap(nums[i], nums[j]);
        }

        if (k <= j)
            return quick_select(nums, l, j, k);
        else
            return quick_select(nums, j + 1, r, k);
    }
};
