//
//  FindFirstAndLastPositionOfElementInSortedArray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) // 右边界
        {
            int mid = l + r + 1>> 1;
            if(nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        
        if(nums[l] != target) return res;
        
        res[1] = l;
        
        l = 0, r = n - 1;
        while(l < r) // 左边界
        {
            int mid = l + r  >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        res[0] = l;
        
        return res;
    }
};

class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        auto size = nums.size();
        int left = 0;
        int right = int(size - 1);
        
        int left_border = -1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left < size && nums[left] == target) { // 右边界
            left_border = left;
            left = 0;
            right = int(size - 1);
            
            int right_border = -1;
            while (left < right) {
                int mid = left + ((right + 1 - left) >> 1);
                if (nums[mid] <= target) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            right_border = left;
            return {left_border, right_border};
        }
        
        return {-1, -1};
    }
};
