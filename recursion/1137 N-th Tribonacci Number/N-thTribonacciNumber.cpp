//
//  N-thTribonacciNumber.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/4.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
using namespace::std;

class Solution {
public:
    int tribonacci(int n) {
        if (cache_map.count(n)) {
            return cache_map[n];
        }
        if (n <= 1) return n;
        if (n == 2) return 1;
        
        int result = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
        cache_map[n] = result;
        
        return result;
    }
    
private:
    unordered_map<int, int> cache_map;
};
