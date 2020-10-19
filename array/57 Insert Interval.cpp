//
//  57 Insert Interval.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> res;

        int i = 0;
        while(i < a.size() && a[i][1] < b[0]) res.push_back(a[i++]);

        if(i < a.size())
        {
            b[0] = min(a[i][0], b[0]);
            while(i < a.size() && a[i][0] <= b[1]) b[1] = max(a[i++][1], b[1]);
        }
        res.push_back(b);
        
        while(i < a.size() && a[i][0] > b[1]) res.push_back(a[i++]);

        return res;
    }
};
