//
//  43 Multiply Strings.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        auto n = num1.length();
        auto m = num2.length();
        vector<int> a, b;
        vector<int> c(n + m);
        
        for (int i = n - 1; i >= 0; i--) {
            a.push_back(num1[i] - '0');
        }
        for (int i = m - 1; i >= 0; i--) {
            b.push_back(num2[i] - '0');
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        
        int carry = 0;
        for (int i = 0; i < c.size(); i++) {
            carry += c[i];
            c[i] = carry % 10;
            carry /= 10;
        }
        
        // 处理前导0
        int k = c.size() - 1;
        while (k > 0 && c[k] == 0) {
            k--;
        }
        
        while (k >= 0) {
            res += c[k] + '0';
            k--;
        }
        return res;
    }
};
