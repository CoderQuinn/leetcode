//
//  Sqrt(x).cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/2.
//  Copyright © 2020 Quinn. All rights reserved.
//

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l < r)
        {
            int mid = (r + 1ll + l) >> 1;
            if(mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
