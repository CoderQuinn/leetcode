//
//  Valid Parentheses.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (auto &c : s) {
            if (stack.empty()) {
                stack.push(c);
            } else {
                if (is_match(stack.top(), c)) {
                    stack.pop();
                } else {
                    stack.push(c);
                }
            }
        }
        return stack.empty();
    }
    
    bool is_match(char a, char b) {
        bool result = false;
        switch (a) {
            case '{':
                if (b == '}') {
                    result = true;
                }
                break;
            case '[':
                if (b == ']') {
                    result = true;
                }
                break;
            case '(':
                if (b == ')') {
                    result = true;
                }
                break;
                
            default:
                break;
        }
        return result;
    }
};

class Solution1 {
public:
/*
 * ascii
 * { 123
 * } 125
 * ( 40
 * ) 41
 * [ 91
 * ] 93
 */
    bool isValid(string s) {
        stack<char> char_stack;
        for(auto c : s) {
            if(c == '{' || c == '[' || c == '(') char_stack.push(c);
            else {
                if(!char_stack.empty() && abs(c - char_stack.top()) <= 2) char_stack.pop();
                else return false;
            }
        }
        return char_stack.empty();
    }
};
