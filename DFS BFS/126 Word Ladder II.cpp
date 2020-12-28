//
//  126 Word Ladder II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> path;
    unordered_map<string, int> dist;
    string beginWord;

    vector<vector<string>> findLadders(string _beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> q;
        unordered_set<string> S;

        beginWord = _beginWord;
        q.push(beginWord);
        dist[beginWord] = 0;
        for (auto &v : wordList)
        {
            S.insert(v);
        }

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();

            string r = t;
            for (int i = 0; i < t.size(); i++)
            {
                t = r;
                for (char j = 'a'; j <= 'z'; j++)
                {
                    if (t[i] == j)
                        continue;
                    t[i] = j;
                    if (S.count(t) && !dist.count(t))
                    {
                        dist[t] = dist[r] + 1;
                        if (t == endWord)
                            break;
                        q.push(t);
                    }
                }
            }
        }

        if (dist.count(endWord) == 0)
            return ans;
        path.push_back(endWord);
        dfs(endWord);
        return ans;
    }

    void dfs(string u)
    {
        if (u == beginWord)
        {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        string tmp = u;
        for (int i = 0; i < u.size(); i++)
        {
            u = tmp;
            for (char j = 'a'; j <= 'z'; j++)
            {
                if (u[i] == j)
                    continue;
                u[i] = j;
                if (dist.count(u) && dist[u] + 1 == dist[tmp])
                {
                    path.push_back(u);
                    dfs(u);
                    path.pop_back();
                }
            }
        }
    }
};
