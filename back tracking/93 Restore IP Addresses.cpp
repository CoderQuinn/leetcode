//
//  93 Restore IP Addresses.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> res;
    string path;
    vector<string> restoreIpAddresses(string s)
    {
        dfs(s, 0, 0);
        return res;
    }

    void dfs(string &s, int u, int cnt)
    {
        if (u == s.size())
        {
            if (cnt == 4)
            {
                path.pop_back();
                res.push_back(path);
            }
            return;
        }
        if (cnt == 4)
            return;

        for (int i = u, t = 0; i < s.size(); i++)
        {
            if (i > u && s[u] == '0') // 有前导0
                break;
            t = t * 10 + s[i] - '0';
            if (t <= 255)
            {
                string tmp = path;

                path += to_string(t) + '.';
                dfs(s, i + 1, cnt + 1);

                path = tmp;
            }
            else
                break;
        }
    }
};
