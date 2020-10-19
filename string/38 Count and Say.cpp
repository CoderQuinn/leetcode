//
//  38 Count and Say.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/25.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 0; i < n - 1; i++)
        {
            string tmp;
            for(int j = 0; j < s.length();)
            {
                int k = j + 1;
                while(k < s.length() && s[k] == s[j]) k++;
                tmp += to_string(k - j) + s[j];
                j = k;
            }
            s = tmp;
        }
        
        return s;
    }
};
