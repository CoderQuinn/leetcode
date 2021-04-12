//
//  283 Move Zeroes.cpp
//  Leetcode
//
//  Created by Quinn on 2021/4/8.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), k = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0) nums[k++] = nums[i];
        }
        while(k < n) nums[k++] = 0;
    }
};
