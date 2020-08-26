//
//  56 Merge Intervals.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int Boundary = INT_MIN;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int left = Boundary, right = Boundary;
        for (int i = 0; i < intervals.size(); ++i) {
            
            if (right >= intervals[i].front()) {
                right = max(right, intervals[i].back());
            } else {
                if (right != Boundary) ans.push_back({left, right});
                
                left = intervals[i].front();
                right = intervals[i].back();
            }
        }
        
        if (right != Boundary) ans.push_back({left, right});
        return ans;
    }
};

