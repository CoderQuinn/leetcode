//
//  204 Count Primes.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

// 线性筛法, O(n)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> st(n + 1);
        vector<int> primes;
        
        for(int i = 2; i < n; i++) {
            if(!st[i]) {
                primes.push_back(i);
            }
            for(int j = 0; primes[j] <= n / i; j++) {
                st[i * primes[j]] = true;
                if(i % primes[j] == 0) break;
            }
        }
        
        return primes.size();
    }
};
