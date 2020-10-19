//
//  41 First Missing Positive.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        auto n = nums.size();
        for (auto &x : nums) {
            if (x != INT_MIN) x -- ;
        }
        
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 0 && nums[i] < n && nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        
        int i = 0;
        for (; i < n; i++) {
            if(nums[i] != i)
                break;
        }
        
        return i + 1;
    }
};
