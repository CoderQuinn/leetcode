//
//  11 Container With Most Water.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while(i < j)  {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};
