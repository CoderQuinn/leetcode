//
//  53 Maximum Subarray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/14.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

// 1. 蛮力枚举
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        size_t size = nums.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += nums[k];
                }
                result = max(result, sum);
            }
        }
        
        return result;
    }
};

// 2. 优化枚举
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        size_t size = nums.size();
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            for (int j = i; j < size; ++j) {
                sum += nums[j];
                result = max(result, sum);
            }
        }
        
        return result;
    }
};

// 3. 分而治之
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        return divide_conquer(nums, 0, nums.size() - 1);
    }
    
    int divide_conquer(vector<int>& nums, long left, long right) {
        if (left == right) return nums[left];
        
        long mid = (left + right) / 2;
        int left_max = divide_conquer(nums, left, mid);
        int right_max = divide_conquer(nums, mid + 1, right);
        int crossing_middle_max = crossing_middle_sub_max(nums, left, mid, right);
        return max(max(left_max, right_max), crossing_middle_max);
    }
    
    int crossing_middle_sub_max(vector<int>& nums, long left, long mid, long right) {
        int left_sum = INT_MIN;
        int right_sum = INT_MIN;
        int sum = 0;
        for (long i = mid; i >= left; i--) {
            sum += nums[i];
            left_sum = max(sum, left_sum);
        }
        
        sum = 0;
        for (long i = mid+1; i <= right; i++) {
            sum += nums[i];
            right_sum = max(sum, right_sum);
        }
        return left_sum + right_sum;
    }
};

// 动态规划
class Solution4
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> f(n);
        vector<int> rect(n);
        f[n - 1] = nums[n - 1];
        int res = f[n - 1];
        
        for (int i = n - 2; i >= 0; i--)
        {
            if (f[i + 1] > 0)
            {
                f[i] = f[i + 1] + nums[i];
            }
            else
            {
                f[i] = nums[i];
            }
            res = max(f[i], res);
        }
        
        
        return res;
    }
};
