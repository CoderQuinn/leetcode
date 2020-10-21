//
//  75 Sort Colors.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/19.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size() - 1;
        while(i <= k)
        {
            if(nums[i] == 0) swap(nums[i++], nums[j++]);
            else if(nums[i] == 2) swap(nums[i], nums[k --]);
            else i++;
        }
    }
};
