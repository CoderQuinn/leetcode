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
        int n = nums.size();
        int l = 0, r = n - 1;
        while(0 < r && nums[0] == nums[r]) r--;
        if(nums[0] <= nums[r]) return nums[0];

        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }

        return nums[l];
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
