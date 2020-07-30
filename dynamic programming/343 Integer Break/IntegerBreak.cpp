//
//  IntegerBreak.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/30.
//  Copyright © 2020 Quinn. All rights reserved.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n <= 0) return 0;
        if (n < 4) return n - 1;
        
        vector<int> result_vector(n + 1, 0);
        result_vector[1] = 1;
        result_vector[2] = 2;
        result_vector[3] = 3;
        
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j < i / 2 + 1; ++j) {
                result_vector[i] = max(result_vector[i], result_vector[j] * result_vector[i - j]);
            }
        }
        
        
        return result_vector[n];
    }
};

class Solution1 {
public:
    int integerBreak(int n) {
        if(n <= 0) return 0;
        if (n < 4) return n - 1;
        
        int x = n / 3;
        int y = n % 3;
        if (y == 1) {
            return pow(3, x - 1) * 4;
        }
        if (y == 2) {
            return pow(3, x) * 2;
        }
        
        return pow(3, x);
    }
};
