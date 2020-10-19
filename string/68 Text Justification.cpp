//
//  68 Text Justification.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/19.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            int j = i + 1;
            int len = words[i].size();
            while(j < n && len + 1 + words[j].size() <= maxWidth)
                len += 1 + words[j++].size();
            
            string line;
            line += words[i];
            if(j == i + 1 || j == words.size())
            {
                for(int k = i + 1; k < j; k++) line += ' ' + words[k];
                while(line.size() < maxWidth) line += ' ';
            }
            else
            {
                int sep_cnt = j - i - 1, r = maxWidth - len + sep_cnt;
                int k = 0;
                while(k < r % sep_cnt)
                    line += string(r / sep_cnt + 1, ' ') + words[++k + i];
                while(k < sep_cnt)
                    line += string(r / sep_cnt, ' ') + words[++k + i];
            }
            res.push_back(line);
            i = j - 1;
        }
        return res;
    }
};
