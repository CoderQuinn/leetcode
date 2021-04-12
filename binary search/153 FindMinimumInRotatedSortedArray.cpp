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
        int n = nums.size() - 1;
        if(nums[0] <= nums[n]) return nums[0];
        int l = 0, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};
