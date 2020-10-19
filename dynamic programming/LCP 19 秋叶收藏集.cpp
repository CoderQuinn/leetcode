//
//  LCP 19 秋叶收藏集.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/2.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    int f[100010][3];
    int minimumOperations(string leaves) {
        int n = leaves.size();
        leaves = ' ' + leaves;
        memset(f, 0x3f, sizeof f);
        f[1][0] = leaves[1] == 'r' ? 0 : 1; // 是否需要操作一次，将'y' - > 'r'
        for(int i = 2; i <= n; i++)
        {
            int to_red = leaves[i] == 'r' ? 0 : 1;
            int to_yellow = leaves[i] == 'y' ? 0 : 1;
            f[i][0] = f[i - 1][0] + to_red; // i为红色
            f[i][1] = min(f[i - 1][0], f[i - 1][1]) + to_yellow; // i为黄色, i - 1可以为红色或黄色
            if(i > 2)
                f[i][2] = min(f[i - 1][1], f[i - 1][2]) + to_red; // i为最后的红色, i - 1可以为最后的红色或黄色
        }
        return f[n][2];
    }
};
