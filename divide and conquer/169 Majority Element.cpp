//
//  169 Majority Element.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/16.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, cnt = 0;

        for(auto &v : nums) {
            if(cnt == 0) {
                ans = v;
                cnt++;
            } else {
                if(ans == v) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }

        return ans;
    }
};
