//
//  56 Merge Intervals.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
        if(a.empty()) return res;
        
        auto n = a.size();
        sort(a.begin(), a.end());
        
        int l = -INF, r = -INF;
        for(int i = 0; i < n; i++)
        {
            if(a[i][0] > r)
            {
                if(r != -INF)
                    res.push_back({l, r});
                l = a[i][0];
                r = a[i][1];
            }
            else
            {
                r = max(r, a[i][1]);
            }
        }
        if(r != -INF)
            res.push_back({l, r});
        
        return res;
    }
};
