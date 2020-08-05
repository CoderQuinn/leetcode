//
//  FibonacciNumber.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
using namespace std;

// memorization recursion
class Solution {
public:
    std::unordered_map<int, int> cache_map;
    int fib(int N) {
        if (cache_map.count(N)) {
            return cache_map[N];
        }
        if (N == 0 || N == 1) {
            return N;
        }
        
        int reslut = fib(N - 1) + fib(N - 2);
        cache_map[N] = reslut;
        return reslut;
    }
};
