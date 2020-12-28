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
        while(l < r && nums[l] == nums[r])
            r--;
        if(nums[l] <= nums[r])
            return nums[l];
        
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};
