//
//  121.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, min_p = INT_MAX;
        for(auto &p : prices) {
            res = max(res, p - min_p);
            min_p = min(min_p, p);
        }
        return res;
    }
};
