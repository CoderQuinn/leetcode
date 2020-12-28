//
//  EvaluateReversePolishNotation.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/24.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
using namespace::std;

/*
 * 1. 当读入的是一个运算数时，把它压入栈中；
 * 2. 当读入的是一个运算符时，就从堆栈中弹出适当数量的运算符并进行计算，计算结果压回到栈中；
 * 3. 处理完整个后缀表达式之后，堆栈顶上的元素就是表达式的结果值。
 */
class Solution0 {
public:
    bool is_operator(const std::string &tokens) {
        if (tokens.length() > 1) return false;
        
        bool result = true;
        switch (tokens[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                break;
            default:
                result = false;
                break;
        }
        return  result;
    }

    bool is_digits(const std::string &str)
    {
        // "-1"
        string temp_str = str;
        if (temp_str[0] == '-' || temp_str[0] == '+') {
            temp_str.erase(temp_str.begin());
        }
        return std::all_of(temp_str.begin(), temp_str.end(), ::isdigit);
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> num_stack;
        for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
            if (is_operator(*it)) {
                int num2 = num_stack.top();
                num_stack.pop();
                int num1 = num_stack.top();
                num_stack.pop();
                
                switch (it->front()) {
                    case '+':
                        num_stack.push(num1 + num2);
                        break;
                    case '-':
                        num_stack.push(num1 - num2);
                        break;
                    case '*':
                        num_stack.push(num1 * num2);
                        break;
                    case '/':
                        num_stack.push(num1 / num2);
                        break;
                    default:
                        // other
                        
                        break;
                }
            } else if(is_digits(*it)) {
                int num = stoi(*it);
                num_stack.push(num);
            } else {
                // other unknown
            }
        }
        return num_stack.top();
    }
};

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;

        for (auto &s : tokens)
        {
            if (s == "+" || s == "-" || s == "/" || s == "*")
            {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();

                if (s == "+")
                    a += b;
                else if (s == "-")
                    a -= b;
                else if (s == "*")
                    a *= b;
                else
                    a /= b;
                stk.push(a);
            }
            else
            {
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
};
