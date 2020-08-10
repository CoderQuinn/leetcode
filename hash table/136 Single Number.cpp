//
//  136 Single Number.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/10.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

// using hash table
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (auto num : nums) {
            if (hash_set.count(num) > 0) {
                hash_set.erase(num);
            }
            hash_set.insert(num);
        }
        return *hash_set.begin();
    }
};

// using bit XOR
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto num : nums) {
            result ^= num;
        }
        return result;
    }
};
