//
//  15 3Sum.cpp
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        long size = nums.size();
        if (size < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        
        
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1, k = size - 1; j < k; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) {
                    k--;
                }
                
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j] ,nums[k]});
                }
            }
        }
        return res;
    }
};
