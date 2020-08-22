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

        auto size = nums.size();
        for(int i = 0; i < size; i++) {
            int another = target - nums[i];
            if(hash_map.count(another) > 0) {
                return {hash_map[another], i};
            }
            hash_map[nums[i]] = i;
        }
        return {-1, -1};
    }
};
