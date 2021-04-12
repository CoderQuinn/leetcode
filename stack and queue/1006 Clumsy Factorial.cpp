//
//  1006 Clumsy Factorial.cpp
//  Leetcode
//
//  Created by Quinn on 2021/4/1.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <stack>

using namespace std;

class Solution
{
public:
    int clumsy(int N)
    {
        stack<int> stk;
        stk.push(N);
        int index = 0;
        while (--N)
        {
            if (index % 4 == 0)
            {
                stk.top() *= N;
            }
            else if (index % 4 == 1)
            {
                stk.top() /= N;
            }
            else if (index % 4 == 2)
            {
                stk.push(N);
            }
            else
            {
                stk.push(-N);
            }

            index++;
        }

        int sum = 0;
        while (!stk.empty())
        {
            sum += stk.top();
            stk.pop();
        }

        return sum;
    }
};
