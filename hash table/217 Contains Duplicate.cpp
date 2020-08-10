//
//  217 Contains Duplicate.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/10.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (auto num : nums) {
            if (hash_set.count(num) > 0) {
                return true;
            }
            hash_set.insert(num);
        }
        return false;
    }
};
