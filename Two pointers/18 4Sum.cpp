//
//  18 4Sum.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 4) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < size; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                for (int k = j + 1, l = size - 1; k < l; k++) { if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    
                    while (k < l - 1 && nums[i] + nums[j] + nums[k] + nums[l - 1] >= target) {
                        l--;
                    }
                    
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
        return res;
    }
};
