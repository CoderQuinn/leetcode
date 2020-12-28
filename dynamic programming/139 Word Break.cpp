//
//  139 Word Break.cpp
//  Leetcode
//
//  Created by Quinn on 2020/11/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    typedef unsigned long long ULL;
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<ULL> hash;
        int n = s.size(), P = 131;
        for (auto word : wordDict)
        {
            ULL h = 0;
            for (auto c : word)
            {
                h = h * P + c;
            }
            hash.insert(h);
        }
        
        vector<bool> f(n + 1);
        f[0] = true;
        s = ' ' + s;
        for (int i = 0; i < n; i++)
        {
            if (f[i])
            {
                ULL h = 0;
                for (int j = i + 1; j <= n; j++)
                {
                    h = h * P + s[j];
                    if (hash.count(h))
                    {
                        f[j] = true;
                    }
                }
            }
        }
        
        return f[n];
    }
};

class Solution1
{
public:
    typedef unsigned long long ULL;
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<ULL> hash;
        int n = s.size(), P = 131;
        for (auto word : wordDict)
        {
            ULL h = 0;
            for (auto c : word)
            {
                h = h * P + c;
            }
            hash.insert(h);
        }
        
        vector<bool> f(n + 1);
        f[n] = true;
        for (int i = n - 1; i >= 0; i--)
        {
            ULL h = 0;
            for (int j = i; j <= n; j++)
            {
                h = h * P + s[j];
                if (hash.count(h) && f[j + 1])
                {
                    f[i] = true;
                    break;
                }
            }
        }
        
        return f[0];
    }
};
