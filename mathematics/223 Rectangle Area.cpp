//
//  223 Rectangle Area.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    typedef long long LL;
    int computeArea(LL A, LL B, LL C, LL D, LL E, LL F, LL G, LL H)
    {
        LL x = max(0LL, min(C, G) - max(A, E));
        LL y = max(0LL, min(D, H) - max(B, F));
        return (D - B) * (C - A) + (H - F) * (G - E) - x * y;
    }
};
