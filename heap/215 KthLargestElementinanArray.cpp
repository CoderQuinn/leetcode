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

// paritition
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        size_t size = nums.size();
        srand(time(0));
        return Kth_select(nums, 0, int(size - 1), int(size - k + 1));
    }
    
    int Kth_select(vector<int>& nums, int p, int r, int k) {
        int q = randomized_partition(nums, p, r);
        if (k == q - p + 1) {
            return nums[q];
        } else if(k < q - p + 1) {
            return Kth_select(nums, p, q - 1, k);
        } else {
            return Kth_select(nums, q + 1, r, k - (q - p + 1));
        }
    }
    
    int randomized_partition(vector<int>& nums, int p, int r) {
        int i = rand() %(r - p + 1) + p;
        swap(nums[i], nums[r]);
        return partition(nums, p, r);
    }
    
    int partition(vector<int>& nums, int p, int r) {

        int x = nums[r];
        int i = p - 1;

        for (int j = p; j < r; ++j) {
            if (nums[j] <= x) {
                i++;
                if (i != j) {
                    swap(nums[j], nums[i]);
                }
            }
        }
        swap(nums[i + 1], nums[r]);
        
        return i + 1;
    }
    
};

// todo: heap
