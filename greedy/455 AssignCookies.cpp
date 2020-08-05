//
//  AssignCookies.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/24.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int count = 0;

        for (vector<int>::iterator it = s.begin(); it != s.end() && count < g.size(); ++it) {
            if (g[count] <= *it) {
                count++;
            }
        }

        return count;
    }
};
