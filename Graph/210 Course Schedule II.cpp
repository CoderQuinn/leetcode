//
//  210 Course Schedule II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        vector<int> res;

        for(auto &e : edges) {
            int b = e[0], a = e[1];
            g[a].push_back(b);
            d[b]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(d[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            res.push_back(t);

            for(auto &e : g[t]) {
                if(--d[e] == 0) {
                    q.push(e);
                }
            }
        }

        if(res.size() < n)
            res = {};
        return res;
    }
};
