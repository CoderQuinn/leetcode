//
//  207 Course Schedule.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

// 拓扑排序
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> d(numCourses);
        int cnt = 0;
        
        for(auto &e : prerequisites) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            d[b]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(d[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            cnt++;
            for(auto &v : g[t]) {
                if(--d[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return cnt == numCourses;
    }
};
