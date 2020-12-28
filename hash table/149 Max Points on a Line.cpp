//
//  149 Max Points on a Line.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/14.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    typedef long double LD;
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;

        for(auto &p : points) {
            int ss = 0, vs = 0;
            unordered_map<LD, int> cnt;
            for(auto &q : points) {
                if(p == q) {
                    ss++;
                } else if(p[0] == q[0]) {
                    vs++;
                } else {
                    LD k = (LD)(p[1] - q[1]) / (p[0] - q[0]);
                    cnt[k]++;
                }
            }
            int c = vs;
            for(auto [k, t] : cnt) c = max(c, t);
            res = max(res, ss + c);
        }

        return res;
    }
};
