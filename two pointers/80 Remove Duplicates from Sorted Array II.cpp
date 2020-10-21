//
//  80 Remove Duplicates from Sorted Array II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/20.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(auto x : nums)
        {
            if(j <= 1 || nums[j - 1] != x || nums[j - 2] != x)
                nums[j++] = x;
        }
        return j;
    }
};
