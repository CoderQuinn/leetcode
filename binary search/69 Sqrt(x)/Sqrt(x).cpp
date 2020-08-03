//
//  Sqrt(x).cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/2.
//  Copyright © 2020 Quinn. All rights reserved.
//


class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while(left <= right){
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            long long result = 1;
            result = result * mid * mid; // prevent int overflow
            if(result == x) {
                return mid;
            }
            else if(result < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};
