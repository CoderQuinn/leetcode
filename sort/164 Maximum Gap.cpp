//
//  164 Maximum Gap.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/20.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    struct Range {
        int min, max;
        bool used;
        Range() : min(INT_MAX), max(INT_MIN), used(false) {
        }
    };

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int Min = INT_MAX, Max = INT_MIN;
        for(auto &v : nums) {
            Min = min(Min, v);
            Max = max(Max, v);
        }
        if(n < 2 || Min == Max)
            return 0;

        vector<Range> r(n - 1);
        int len = (Max - Min + n - 2) / (n - 1);

        for(auto &x : nums) {
            if(x == Min) continue;
            int k = (x - Min - 1) / len;
            r[k].used = true;
            r[k].min = min(r[k].min, x);
            r[k].max = max(r[k].max, x);
        }

        int res = 0;
        for(int i = 0, last = Min; i < n - 1; i++) {
            if(r[i].used) {
                res = max(res, r[i].min - last);
                last = r[i].max;
            }
        }
        
        return res;
    }
};
