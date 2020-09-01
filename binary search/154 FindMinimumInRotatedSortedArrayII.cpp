//
//  FindMinimumInRotatedSortedArrayII.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <stdio.h>
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            auto mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right--;
            }
        }
        
        return nums[left];
    }
};

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right && nums[left] == nums[right]) --right;

        if (nums[left] <= nums[right]) return nums[left];
        
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < nums[0]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return nums[left];
    }
};
