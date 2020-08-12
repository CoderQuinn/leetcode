//
//  219 Contains Duplicate II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/11.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int>::iterator it = hash_map.find(nums[i]);
            if (it != hash_map.end()) {
                if (i != it->second && abs(it->second - i) <= k) {
                    return true;
                } else {
                    it->second = i;
                }
                
            } else {
                hash_map.insert(make_pair(nums[i], i));
            }
        }
        return false;
    }
};
