//
//  BasicCalculator.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/23.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
using namespace::std;

/*
 思路：
 
 已知由于只有加减运算，不用比较运算符号优先级
 思路：定义两个栈：number_stack用于存储数据，op_stack用于存储操作符
 1. 从左往右扫描，遇到操作数入数据栈;
 2. 遇到操作符 + 或 - 时，若操作符栈为空，直接入操作符栈；若栈不为空，且栈顶不为左括号，则从数据栈弹出两个元素，从 操作符栈弹出一个操作符进行计算，将结果并压入数据栈；直到栈顶为左括号
 3. 若是左括号，直接入操作符栈,继续扫描
 4. 若遇到的是右括号，则从数据栈弹出两个元素，从操作弹出一个操作符进行计算，并将结果加入到数据栈中，直到栈顶为左括号，弹出左括号后，继续扫描
 */

class Solution
{
public:
    void calc(stack<int> &num, stack<char> &op)
    {
        int b = num.top();
        num.pop();
        int a = 0;
        if (!num.empty())
        {
            a = num.top();
            num.pop();
        }

        auto c = op.top();
        op.pop();

        int x = 0;
        if (c == '+')
        {
            x = a + b;
        }
        else if (c == '-')
        {
            x = a - b;
        }
        num.push(x);
    }

    int calculate(string s)
    {
        stack<int> num;
        stack<char> op;
        for (int i = 0; i < s.size(); i++)
        {
            auto c = s[i];
            if (c == ' ')
                continue;
            else if (isdigit(c))
            {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                {
                    x = x * 10 + (s[j++] - '0');
                }
                num.push(x);
                i = j - 1;
            }
            else if (c == '(')
            {
                op.push(c);
            }
            else if (c == ')')
            {
                if (!op.empty() && op.top() != '(')
                {
                    calc(num, op);
                }
                if (!op.empty() && op.top() == '(')
                    op.pop();
            }
            else
            {
                while (!op.empty() && op.top() != '(')
                {
                    calc(num, op);
                }
                op.push(c);
            }
        }
        while (!op.empty())
        {
            calc(num, op);
        }
        return num.top();
    }
};

/*
 * 思路3: https://leetcode-cn.com/problems/basic-calculator/solution/ji-ben-ji-suan-qi-by-leetcode/
 */
class Solution3 {
public:
    int calculate(string s) {
        int num = 0;
        int result = 0;
        int sign = 1;
        stack<int> calculate_stack;
        
        for (auto &c : s) {
            switch (c) {
                case '+':
                    result += sign * num;
                    num = 0;
                    sign = 1;
                    break;
                case '-':
                    result += sign * num;
                    num = 0;
                    sign = -1;
                    break;
                case '(':
                    calculate_stack.push(result);
                    calculate_stack.push(sign);
                    
                    result = 0;
                    sign = 1;
                    break;
                case ')':
                    result += sign * num; // )括号左边的值
                    
                    result *= calculate_stack.top(); // (括号前的符号
                    calculate_stack.pop();
                    
                    result += calculate_stack.top(); // 之前的计算结果
                    calculate_stack.pop();
                    
                    num = 0;
                    
                    break;
                case ' ':
                    break;
                default:
                    if (isdigit(c)) {
                        num = c - '0' + num * 10;
                    }
                    break;
            }
        }
        
        return result + (sign * num);
    }
};

// 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格
class Solution4 {
public:
    int calculate(string s) {
        vector<string> vector = shunting_yard_algorithm(s);
        return evalRPN(vector);
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> num_stack;
        for (size_t i = 0; i < tokens.size(); ++i) {
            string &curr = tokens[i];
            if (curr == "+" || curr == "-") {
                int num2 = num_stack.top();
                num_stack.pop();
                int num1 = num_stack.top();
                num_stack.pop();
                int sum;
                if (curr == "-") {
                    sum = num1 - num2;
                } else {
                    sum = num1 + num2;
                }
                num_stack.push(sum);
            } else {
                int num = stoi(curr);
                num_stack.push(num);
            }
        }
        
        return num_stack.top();
    }
    
    vector<string> shunting_yard_algorithm(string s) {
        vector<string> str_vec;
        stack<char> operator_stack;
        
        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]) {
                case '+':
                case '-':
                    if (!operator_stack.empty() && (operator_stack.top() == '+' || operator_stack.top() == '-')) {
                        string op;
                        op += operator_stack.top();
                        operator_stack.pop();
                        
                        str_vec.push_back(op);
                    }
                    operator_stack.push(s[i]);
                    break;
                case '(':
                    operator_stack.push(s[i]);
                    break;
                case ')':
                    while (operator_stack.top() != '(') {
                        string op;
                        op += operator_stack.top();
                        operator_stack.pop();
                        
                        str_vec.push_back(op);
                    }
                    operator_stack.pop();
                    break;
                case ' ':
                    continue;
                    break;
                default:
                    if (isdigit(s[i])) {
                        string num_str;
                        num_str += s[i];
                        while (i + 1 < s.length() && isdigit(s[i + 1])) {
                            ++i;
                            num_str += s[i];
                        }
                        str_vec.push_back(num_str);
                    }
                    break;
            }
        }
        while (!operator_stack.empty()) {
            string op;
            op += operator_stack.top();
            operator_stack.pop();
            
            str_vec.push_back(op);
        }
        return str_vec;
    }
};
