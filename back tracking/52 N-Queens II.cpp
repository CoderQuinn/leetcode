//
//  52 N-Queens II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<bool> col, dg, udg;
    int m;
    
    int totalNQueens(int n) {
        m = n;
        
        col.resize(n);
        dg.resize(2 * n);
        udg.resize(2 * n);
        
        return dfs(0);
    }
    
    int dfs(int u)
    {
        if(u == m)
        {
            return 1;
        }
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            if (!col[i] && !dg[u - i + m] && !udg[u + i]) {
                col[i] = dg[u - i + m] = udg[u + i] = true;
                res += dfs(u + 1);
                col[i] = dg[u - i + m] = udg[u + i] = false;
            }
        }
        return res;
    }
};

