//
//  K-thSymbolInGrammar.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

// 暴力枚举-。-
class Solution {
public:
    int kthGrammar(int N, int K) {
        vector<int> result(1 << N, 0);
        for (int i = 1; i < N; ++i) {
            for (int j = (1 << (N - 1)) -1; j >= 0; --j) {
                result[2 * j] = result[j];
                result[2 * j + 1] = 1 - result[j];
            }
        }
        return result[K-1];
    }
};

/*
第 K 位的父位应该是第 (K+1) / 2 位。
如果父位是 0，那么这一位就是 1 - (K%2)。
如果父位是 1，那么这一位就是 K%2。
*/
class Solution1 {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        
        int parent_result = kthGrammar(N -1, (K+1) / 2);
        if (parent_result & 1) {
            return 1 - K % 2;
        } else {
            return K % 2;
        }
    }
};
