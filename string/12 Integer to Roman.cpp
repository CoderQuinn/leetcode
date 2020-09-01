//
//  12 Integer to Roman.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/29.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        
        int values[] = {
            1, 4, 5, 9,
            10, 40, 50, 90,
            100, 400, 500, 900,
            1000
        };

        string romans[] = {
            "I", "IV", "V", "IX",
            "X", "XL", "L", "XC",
            "C", "CD", "D", "CM",
            "M"
        };
        
        for (int i = 12; i >= 0; i--) {
            while (num >= values[i]) {
                num -= values[i];
                res += romans[i];
            }
        }
        
        return res;
    }
};
