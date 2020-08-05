//
//  DecodeString.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        std::string result;
        std::vector<char> char_vec;
        std::stack<int> number_stack;
        
        int number = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                number = c - '0' + 10 * number;
            } else {
                if (c == '[') {
                    number_stack.push(number);
                    number = 0;
                    char_vec.push_back(c);
                } else if(c == ']') {
                    int k = number_stack.top();
                    number_stack.pop();
                    
                    string curr;
                    while (char_vec.back() != '[') {
                        curr += char_vec.back();
                        char_vec.pop_back();
                    }
                    
                    char_vec.pop_back();
                    
                    while (k > 0) {
                        for (int i = curr.size() - 1; i >= 0; i--) {
                            char_vec.push_back(curr[i]);
                        }
                        k--;
                    }
                    
                } else {
                    char_vec.push_back(c);
                }
            }
        }
        
        for (auto &c : char_vec) {
            result += c;
        }
        
        return result;
    }
};
