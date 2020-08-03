//
//  FindPeakElement.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using std::vector;
/*
 * 1. 降序序列
 * 2. 升序序列
 * 3.
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else { // nums[mid] >= nums[mid + 1]
                right = mid;
            }
        }
        return left;
    }
};
