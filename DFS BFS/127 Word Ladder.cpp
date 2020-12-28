//
//  127 Word Ladder.cpp
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
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> q;
        unordered_set<string> set;
        unordered_map<string, int> dist;

        for (auto &v : wordList)
        {
            set.insert(v);
        }
        q.push(beginWord);
        dist[beginWord] = 1;

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
                    if(t[i] == j) continue;
                    t[i] = j;
                    if (set.count(t) && !dist.count(t))
                    {
                        dist[t] = dist[r] + 1;
                        if (t == endWord)
                        {
                            return dist[t];
                        }
                        q.push(t);
                    }
                }
            }
        }

        return 0;
    }
};
