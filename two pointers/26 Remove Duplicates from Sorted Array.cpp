//
//  26 Remove Duplicates from Sorted Array.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(auto x : nums)
        {
            if(k < 1 || nums[k - 1] != x)
            {
                nums[k++] = x;
            }
        }
        return k;
    }
};
