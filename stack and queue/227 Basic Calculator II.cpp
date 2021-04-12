//
//  227 Basic Calculator II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    stack<int> num;
    stack<char> op;

    void calc()
    {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();

        char c = op.top();
        op.pop();

        int r = 0;
        if (c == '+')
        {
            r = a + b;
        }
        else if (c == '-')
        {
            r = a - b;
        }
        else if (c == '*')
        {
            r = a * b;
        }
        else
        {
            r = a / b;
        }

        num.push(r);
    }

    int calculate(string s)
    {
        unordered_map<char, int> hash;
        hash['+'] = hash['-'] = 0;
        hash['*'] = hash['/'] = 1;

        for (int i = 0; i < s.size(); i++)
        {
            auto c = s[i];
            if (c == ' ')
                continue;
            else if (isdigit(c))
            {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                {
                    x = x * 10 + (s[j++] - '0');
                }
                i = j - 1;
                num.push(x);
            }
            else
            {
                while (!op.empty() && hash[op.top()] >= hash[c])
                {
                    calc();
                }
                op.push(c);
            }
        }

        while (!op.empty())
        {
            calc();
        }
        return num.top();
    }
};
