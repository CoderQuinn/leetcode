//
//  137 只出现一次的数字 II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <unordered_set>
using namespace std;

// 基于状态自动机，推公式
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (auto x : nums) {
            one = (one ^ x) & ~two;
            two = (two ^ x) & ~one;
        }
        return one;
    }
};

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        long sum2 = 0;
        for (auto num : nums) {
            sum2 += num;
            set.insert(num);
        }
        
        long sum1 = 0;
        for (auto num : set) {
            sum1 += num;
        }
        return (sum1 * 3 - sum2) / 2;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int size = sizeof(int) * 8;
        int res = 0;
        vector<int> count(size, 0);
        for(auto num : nums) {
            for(int i = 0; i < size; i++) {
                if(num >> i & 1) {
                    count[i]++;
                }
            }
        }
        
        int n = 3;
        for(int i = 0; i < size; i++) {
            count[i] %= n;
            if(count[i] > 0) {
                res |= (1 << i);
            }
        }
        
        return res;
    }
};
