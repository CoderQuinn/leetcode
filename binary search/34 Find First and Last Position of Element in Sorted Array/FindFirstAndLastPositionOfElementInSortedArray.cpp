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
        vector<int> result_vector(2, -1);
        if (nums.empty()) return result_vector;

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                break;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if (nums[mid] == target) {
            left = mid - 1;
            right = mid + 1;
            while (left >= 0 && nums[left] == target) {
                left--;
            }
            
            while (right < nums.size() && nums[right] == target) {
                right++;
            }
            
            result_vector[0] = left + 1;
            result_vector[1] = right - 1;
        }
 
        return result_vector;
    }
};
