//
//  724 Find Pivot Index.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

// 前缀和,空间复杂度O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> sums(size + 1, 0);
        for (int i = 0; i < size; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        
        int ans = -1;
        for (int i = 1; i <= size; i++) {
            if (sums[i-1] == sums[size] - sums[i]) {
                ans = i-1;
                break;
            }
        }
        return ans;
    }
};
