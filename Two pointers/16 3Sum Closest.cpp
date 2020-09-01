//
//  16 3Sum Closest.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MIN;
        int difference = INT_MAX;

        sort(nums.begin(), nums.end());
        long size = nums.size();
        
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1, k = size - 1; j < k; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= target) {
                    k--;
                }
                int sum  = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < difference) {
                    difference = abs(sum - target);
                    res = sum;
                }

                if (j < k - 1) {
                    sum  = nums[i] + nums[j] + nums[k - 1];
                    if (abs(sum - target) < difference) {
                        res = sum;
                    }
                }
            }
        }
        
        return res;
    }
};
