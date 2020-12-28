//
//  168 Excel Sheet Column Title.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/16.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n) {
            n--;
            res += 'A' + n % 26;
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution0 {
public:
    string convertToTitle(int n) {
        string res;
        if(n > 26)
            res += convertToTitle((n - 1) / 26);
        res += (n - 1) % 26 + 'A';
        return res;
    }
};
