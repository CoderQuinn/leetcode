//
//  58 Length of Last Word.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                int j = i;
                while(j >= 0 && s[j] != ' ') j--;
                return i - j;
            }
        }
        
        return 0;
    }
};

class Solution1 {
public:
    int lengthOfLastWord(string s) {
        stringstream ssin(s);
        int res = 0;
        string word;
        while (ssin >> word) {
            res = word.size();
        }
        
        return res;
    }
};
