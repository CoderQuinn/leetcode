//
//  66 Plus One.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/18.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for(auto &num : digits)
        {
            carry += num;
            num = carry % 10;
            carry /= 10;
        }
        if(carry > 0)
            digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
