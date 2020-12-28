//
//  214 Shortest Palindrome.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/23.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.length();
        string p = ' ' + s + '#' + string(s.rbegin(), s.rend());

        vector<int> ne(2 * n + 2);
        ne[1] = 0;
        for (int i = 2, j = 0; i <= 2 * n + 1; i++)
        {
            while (j > 0 && p[j + 1] != p[i])
            {
                j = ne[j];
            }

            if (p[j + 1] == p[i])
            {
                j++;
            }

            ne[i] = j;
        }
        int len = ne[2 * n + 1];

        string l = p.substr(1, len), r = p.substr(1 + len, n - len);
        return string(r.rbegin(), r.rend()) + l + r;
    }
};
