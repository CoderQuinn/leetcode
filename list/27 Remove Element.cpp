//
//  27 Remove Element.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
                nums[j++] = nums[i];
        }
        
        return j;
    }
};
