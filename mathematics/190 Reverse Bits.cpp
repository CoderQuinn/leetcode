//
//  190 Reverse Bits.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        for(int i = 0; i < 32; i++) {
            res = (res << 1) + (n >> i & 1);
        }
        return res;
    }
};
