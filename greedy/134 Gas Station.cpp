//
//  134 Gas Station.cpp
//  Leetcode
//
//  Created by Quinn on 2020/11/25.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0, j; i < n;) {
            int left = 0;
            for (j = 0; j < n; j++) {
                int k  = (i + j) % n;
                left += gas[k] - cost[k];
                if (left < 0) {
                    break;
                }
            }
            
            if (j == n) return i;
            
            i = i + j + 1;
        }
        
        return -1;
    }
};
