//
//  1 Two Sum.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/10.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hash_map.find(target - nums[i]);
            if (it != hash_map.end()) {
                return {it->second, i};
            }
            hash_map.insert(make_pair(nums[i], i));
        }
        return {};
    }
};
