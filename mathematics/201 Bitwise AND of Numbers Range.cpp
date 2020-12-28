//
//  201 Bitwise AND of Numbers Range.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for(int i = 31; i >= 0; i--) {
            if((m >> i & 1) != (n >> i & 1)) break;
            if(m >> i & 1) res += 1 << i;
        }
        return res;
    }
};
