//
//  71 Simplify Path.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/19.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        if(path.back() != '/') path += '/';
        for(auto &c : path)
        {
            if(c != '/')
                tmp += c;
            else
            {
                if(tmp == "." || tmp.empty());
                else if(tmp == "..")
                {
                    while(!res.empty() && res.back() != '/') res.pop_back();
                    if(!res.empty()) res.pop_back();
                }
                else
                {
                    res += '/' + tmp;
                }
                tmp.clear();
            }
        }
        
        if(res.empty()) res += '/';
        return res;
    }
};
