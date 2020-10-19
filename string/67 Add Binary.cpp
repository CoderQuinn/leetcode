//
//  67 Add Binary.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/18.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
using namespace::std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res;
        int carry = 0;
        for(int i = 0; i < a.size() || i < b.size() || carry > 0; i++)
        {
            if(i < a.size()) carry += a[i] - '0';
            if(i < b.size()) carry += b[i] - '0';
            res += to_string(carry % 2);
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
