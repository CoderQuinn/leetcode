//
//  1805 Number of Different Integers in a String.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/29.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word)
    {
        unordered_set<string> nums;
        for(int i = 0; i < word.size(); i++)
        {
            if(!isdigit(word[i])) continue;
            int j = i;
            string s;
            while(j < word.size() && isdigit(word[j]))
            {
                s += word[j++];
            }
            
            int k = 0;
            while(k + 1 < s.size() && s[k] == '0')
            {
                k++;
            }
            nums.insert(s.substr(k));
            i = j;
        }
        return nums.size();
    }
};
