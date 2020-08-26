//
//  7 Reverse Integer.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/23.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int x1 = x;
        int ans = 0;
        while (x1) {
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            ans = ans * 10 + x1 % 10;
            x1 /= 10;
        }
        return ans;
    }
};
