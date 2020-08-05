//
//  Find the Duplicate Number.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/4.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace::std;
// 暴力枚举，时间: o(n*n), 空间: o(1)
// 哈希表，时间: o(n), 空间: o(n)

/*
 *
 1. 不能更改原数组（假设数组是只读的）。
 2. 只能使用额外的 O(1) 的空间。
 3. 时间复杂度小于 O(n2) 。
 4. 数组中只有一个重复的数字，但它可能不止重复出现一次。
 */
// binary serarch, not a good solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            int count = 0;
            for (auto num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            
            if (count > mid) { // [1，mid]之间有重复
                right = mid;
            } else { // (mid，n]之间有重复
                left = mid + 1;
            }
            
        }
        
        return left;
    }
};

// graph
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow != fast);
        
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
