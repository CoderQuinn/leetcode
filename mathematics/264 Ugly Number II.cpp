//
//  264 Ugly Number II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        res.push_back(1);
        int i = 0, j = 0, k = 0;
        while(res.size() < n)
        {
            int val = min(2 * res[i], min(3 * res[j], 5 * res[k]));
            res.push_back(val);
            if(2 * res[i] == val) i++;
            if(3 * res[j] == val) j++;
            if(5 * res[k] == val) k++;
        }

        return res.back();
    }
};
