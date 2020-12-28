//
//  135 Candy.cpp
//  Leetcode
//
//  Created by Quinn on 2020/11/25.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> f;
    vector<int> w;
    int n;
    
    int candy(vector<int>& ratings) {
        n = ratings.size();
        f.resize(n, -1);
        w = ratings;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += dp(i);
        }
        
        return res;
    }
    
    int dp(int u) {
        if (f[u] != -1) {
            return f[u];
        }
        
        f[u] = 1;
        if(u > 0 && w[u] > w[u - 1]) {
            f[u] = max(f[u], dp(u - 1) + 1);
        }
        
        if(u + 1 < n && w[u] > w[u + 1]) {
            f[u] = max(f[u], dp(u + 1) + 1);
        }
        
        return f[u];
    }
};
