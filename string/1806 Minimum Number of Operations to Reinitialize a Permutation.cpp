//
//  1806 Minimum Number of Operations to Reinitialize a Permutation.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/29.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    void work(vector<int> &q)
    {
        int n = q.size();
        vector<int> w(n);
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                w[i] = q[i / 2];
            }
            else
            {
                w[i] = q[n / 2 + (i - 1) / 2];
            }
        }
        q = w;
    }

    bool check(vector<int> &q)
    {
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i] != i)
                return false;
        }
        return true;
    }

    int reinitializePermutation(int n)
    {
        vector<int> q;
        for (int i = 0; i < n; i++)
            q.push_back(i);
        int cnt = 0;

        while (true)
        {
            cnt++;
            work(q);
            if (check(q))
                break;
        }

        return cnt;
    }
};
