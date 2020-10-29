//
//  122 Best Time to Buy and Sell Stock II.cpp
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
        int res = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};
