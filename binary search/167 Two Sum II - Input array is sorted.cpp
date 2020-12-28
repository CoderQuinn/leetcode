//
//  Two Sum II - Input array is sorted.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/4.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

// binary search
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int left = i + 1;
            int right = numbers.size() - 1;
            int val = target - numbers[i];
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (val == numbers[mid]) {
                    return {i + 1, mid + 1};
                } else if (val < numbers[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return {-1, -1};
    }
};

// two pointer
class Solution0
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0, j = n - 1; i < j; i++)
        {
            while (i < j && numbers[i] + numbers[j] > target)
            {
                j--;
            }
            if (numbers[i] + numbers[j] == target)
            {
                return {i + 1, j + 1};
            }
        }
        return {-1, -1};
    }
};
