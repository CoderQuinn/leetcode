//
//  31 Next Permutation.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto size = nums.size();
        int i = int(size - 1);
        while (i > 0 && nums[i - 1] >= nums[i]) { // 找到第一个非降序的分隔点
            i--;
        }
        // i - 1, i是升序对
        if (i == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int j = i;
            while (j < size && nums[j] > nums[i - 1]) { // 找到比i - 1大的最小值
                j++;
            }
            
            swap(nums[i - 1], nums[j - 1]);
            reverse(nums.begin() + i, nums.end());
        }
    }
};
