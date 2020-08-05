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
using namespace::std;

/*
 思路1：
 
 已知由于只有加减运算，不用比较运算符号优先级
 思路：定义两个栈：number_stack用于存储数据，op_stack用于存储操作符
 1. 从左往右扫描，遇到操作数入数据栈;
 2. 遇到操作符 + 或 - 时，若操作符栈为空，直接入操作符栈；若栈不为空，且栈顶不为左括号，则从数据栈弹出两个元素，从 操作符栈弹出一个操作符进行计算，将结果并压入数据栈；直到栈顶为左括号
 3. 若是左括号，直接入操作符栈,继续扫描
 4. 若遇到的是右括号，则从数据栈弹出两个元素，从操作弹出一个操作符进行计算，并将结果加入到数据栈中，直到栈顶为左括号，弹出左括号后，继续扫描
 */

class Solution1 {
public:
    void compute (std::stack<int> &number_stack, std::stack<char> &operator_stack) {
        int num2 = number_stack.top();
        number_stack.pop();
        int num1 = number_stack.top();
        number_stack.pop();
        
        int result = 0;
        if (operator_stack.top() == '+') {
            result = num1 + num2;
        } else {
            result = num1 - num2;
        }
        number_stack.push(result);
        operator_stack.pop();
    }
    
    int calculate(string s) {
        std::stack<int> number_stack;
        std::stack<char> operator_stack;
        int num = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]) {
                case '+':
                case '-':
                    if (operator_stack.empty() || operator_stack.top() == '(') {
                    } else {
                        compute(number_stack, operator_stack);
                    }
                    operator_stack.push(s[i]);
                    break;
                case '(':
                    operator_stack.push(s[i]);
                    break;
                case ')':
                    while (operator_stack.top() != '(') {
                        compute(number_stack, operator_stack);
                    }
                    operator_stack.pop();
                    break;
                case ' ':
                    break;
                default:
                    if (isdigit(s[i])) {
                        num = s[i] - '0';
                        while (i + 1 < s.length() && isdigit(s[i+1])) {
                            ++i;
                            num = s[i] - '0' + num * 10;
                        }
                        number_stack.push(num);
                        num = 0;
                    }
                    break;
            }
        }
        if (!operator_stack.empty()) {
            compute(number_stack, operator_stack);
        }
        
        return number_stack.top();
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
