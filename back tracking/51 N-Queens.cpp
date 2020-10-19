//
//  51 N-Queens.cpp
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
    vector<vector<string>> ans;
    vector<string> path;
    vector<bool> col, dg, udg;
    int m;
    
    vector<vector<string>> solveNQueens(int n) {
        m = n;
        
        path.resize(n, string(n, '.'));
        col.resize(n);
        dg.resize(2 * n);
        udg.resize(2 * n);
        
        dfs(0);
        return ans;
    }
    
    void dfs(int u)
    {
        if(u == m)
        {
            ans.push_back(path);
            return;
        }
        
        for (int i = 0; i < m; i++) {
            if (!col[i] && !dg[u - i + m] && !udg[u + i]) {
                col[i] = dg[u - i + m] = udg[u + i] = true;
                path[u][i] = 'Q';
                dfs(u + 1);
                col[i] = dg[u - i + m] = udg[u + i] = false;
                path[u][i] = '.';
            }
        }
    }
    
};
