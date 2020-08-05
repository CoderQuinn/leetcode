//
//  ClimbingStairs.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    std::unordered_map<int, int> cache_map;
    int climbStairs(int n) {
        if (cache_map.count(n)) return cache_map[n];
        
        if (n <= 2) return n;
        
        int result = climbStairs(n-1) + climbStairs(n-2);
        cache_map[n] = result;
        
        return result;
        
    }
};
