//
//  120 Triangle.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

// 从上往下 + 滚动数组
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        const int INF = 0x3f3f3f3f;
        int n = triangle.size();
        int m = triangle.back().size();
        
        vector<vector<int>> f(2, vector<int>(m + 1, INF));
        
        f[1][1] = triangle[0][0];
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j <= i; j++) {
                f[i & 1][j] = min(f[i - 1 & 1][j], f[i - 1 & 1][j - 1]) + triangle[i - 1][j - 1];
            }
        }
        
        int value = INF;
        for (int i = 1; i <= m; i++) {
            value = min(value, f[n & 1][i]);
        }
        return value;
    }
};

class Solution1 {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        const int INF = 0x3f3f3f3f;
        int n = triangle.size();
        int m = triangle.back().size();
        
        vector<int> f(m + 1, INF);
        
        f[1] = triangle[0][0];
        for (int i = 2; i <= n; i ++) {
            for (int j = i; j >= 1; j--) {
                f[j] = min(f[j], f[j - 1]) + triangle[i - 1][j - 1];
            }
        }
        
        int value = INF;
        for (int i = 1; i <= m; i++) {
            value = min(value, f[i]);
        }
        return value;
    }
};

// 从下而上 + 滚动数组
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle.back().size();
        
        vector<vector<int>> f(2, vector<int>(m + 1));
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                f[i & 1][j] = min(f[i + 1 & 1][j], f[i + 1 & 1][j + 1]) + triangle[i][j];
            }
        }
        return f[0][0];
    }
};

class Solution3 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle.back().size();
        
        vector<int> f(m + 1);
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                f[j] = min(f[j], f[j + 1]) + triangle[i][j];
            }
        }
        return f[0];
    }
};
