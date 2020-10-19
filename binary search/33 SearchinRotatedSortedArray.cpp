//
//  SearchinRotatedSortedArray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/2.
//  Copyright © 2020 Quinn. All rights reserved.
//
#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) // 找到分隔点
        {
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        
        if(target >= nums[0]) {
            l = 0;
        } else {
            l = l + 1;
            r = n - 1;
        }
        
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] >= target) r= mid;
            else l = mid + 1;
        }
        
        if(l < n && nums[l] == target)
            return l;
        else
            return -1;
    }
};
