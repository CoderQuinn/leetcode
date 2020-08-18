//
//  315 Count of Smaller Numbers After Self.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/17.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

// 蛮力枚举法, 时间复杂度：O(n*n)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    result[i]++;
                }
            }
        }
        
        return result;
    }
    
};

// 分而治之，排序求解
class Solution1 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        
        return result;
    }
    
    void countSmaller(vector<int>& nums, vector<int>& count, int left, int right) {

    }
    
};
