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
        int k = 0;
        for(auto x : nums)
        {
            if(k < 2 || x != nums[k - 2])
            {
                nums[k++] = x;
            }
        }
        return k;
    }
};
