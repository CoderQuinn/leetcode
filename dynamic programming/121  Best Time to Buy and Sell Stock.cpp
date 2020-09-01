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
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans += max(0, prices[i] - prices[i-1]);
        }
        return ans;
    }
};
