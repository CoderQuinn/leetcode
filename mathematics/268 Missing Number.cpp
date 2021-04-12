//
//  268 Missing Number.cpp
//  Leetcode
//
//  Created by Quinn on 2021/4/1.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n * (n + 1) / 2;
        for(auto &x : nums) res -= x;
        return res;
    }
};
