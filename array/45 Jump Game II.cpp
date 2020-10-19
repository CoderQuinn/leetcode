//
//  45 Jump Game II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        auto n = nums.size();
        vector<int> f(n);
        
        for(int i = 1, j = 0; i < n; i++)
        {
            while(j + nums[j] < i)
            {
                j++;
            }
            f[i] = f[j] + 1;
        }

        return f[n - 1];
    }
};
