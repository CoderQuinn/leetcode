//
//  179 Largest Number.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/17.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    static bool cmp(int x, int y) {
        string a = to_string(x), b = to_string(y);
        return a + b > b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), cmp);
        for(auto &v : nums) {
            res += to_string(v);
        }
        int k = 0;
        while(k + 1 < res.size() && res[k] == '0') {
            k++;
        }
        return res.substr(k);
    }
};
