//
//  ValidPerfectSquare.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid == num) {
                return true;
            } else if(mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
