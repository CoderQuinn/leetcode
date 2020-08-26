//
//  6 ZigZag Conversion.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/23.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string answer;
        for (int i = 0; i < numRows; ++i) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.length(); j += 2 * numRows - 2) {
                    answer += s[j];
                }
            } else {
                for (int j = i, k = 2 *numRows - 2 - i; j < s.length() || k < s.length(); j += 2 * numRows - 2, k += 2 * numRows - 2 ) {
                    if (j < s.length()) {
                        answer += s[j];
                    }
                    
                    if (k < s.length()) {
                        answer += s[k];
                    }
                }
            }
        }
        return answer;
    }
};
