//
//  233 Number of Digit One.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/17.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> nums;
    int get_part(int l, int r)
    {
        int res;
        for (int i = l; i >= r; i--)
        {
            res = 10 * res + nums[i];
        }
        return res;
    }

    int countDigitOne(int n)
    {
        if (n <= 0)
            return 0;
        int res = 0;
        while (n)
        {
            nums.push_back(n % 10);
            n /= 10;
        }

        int m = nums.size();
        for (int i = m - 1; i >= 0; i--)
        {
            int left = get_part(m - 1, i + 1);
            int right = get_part(i - 1, 0);
            int p = pow(10, i);

            auto d = nums[i];
            if (d == 0)
            {
                res += left * p;
            }
            else if (d == 1)
            {
                res += left * p + right + 1;
            }
            else
            {
                res += (left + 1) * p;
            }
        }

        return res;
    }
};
