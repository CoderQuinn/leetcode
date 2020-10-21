//
//  81 Search in Rotated Sorted Array II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        int n = nums.size();
        int j = n - 1;
        while(j >= 0 && nums[0] == nums[j]) j--;
        if(j < 0) return nums[0] == target;

        int l = 0, r = j;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        if(target >= nums[0])
        {
            l = 0;
        }
        else
        {
            l = l + 1;
            r = j;
        }

        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return  r < n && nums[r] == target;
    }
};
