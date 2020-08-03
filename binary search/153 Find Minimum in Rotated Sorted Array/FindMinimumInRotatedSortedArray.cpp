//
//  FindMinimumInRotatedSortedArray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//
#include <vector>
#include <climits>
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (nums[right] < nums[mid]) { // 右边无序
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return nums[left];
    }
};
