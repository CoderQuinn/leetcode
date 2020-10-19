//
//  55 Jump Game.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto n = nums.size();
        vector<int> f(n);
        
        for(int i = 0, j = 0; i < n; i++)
        {
            if(j < i)
                return false;
            j = max(j, i + nums[i]);
        }

        return true;
    }
};
