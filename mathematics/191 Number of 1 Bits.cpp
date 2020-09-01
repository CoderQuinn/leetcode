//
//  191 Number of 1 Bits.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t flag = 1;
        int count = 0;
        while (flag) {
            if (n & flag) {
                count++;
            }
            flag = flag << 1;
        }
        return count;
    }
};

class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            count++;
            n = (n - 1) & n;
        }
        return count;
    }
};
