//
//  8 String to Integer (atoi).cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/23.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int k = 0;
        
        while (str[k] == ' ') k++;
        if (k == str.length()) return 0;

        int minus = 1;
        if (str[k] == '-') {
            minus = -1;
            k++;
        } else if (str[k] == '+') k++;

        int ans = 0;
        while (k < str.length() && isdigit(str[k])) {
            int x = str[k] - '0';
            if (minus > 0 && ans > (INT_MAX - x) / 10) {
                return INT_MAX;
            }
            
            if (minus < 0 && - ans < (INT_MIN + x) / 10) {
                return INT_MIN;
            }
            
            if (minus < 0 && -ans * 10  == INT_MIN + x) {
                return INT_MIN;
            }
            
            ans = 10 * ans + x;
            k++;
        }
        
        if(ans != 0) ans *= minus;

        return ans;
    }
};

