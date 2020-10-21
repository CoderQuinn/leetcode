//
//  89 Gray Code.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        
        while(n--)
        {
            for(int k = res.size() - 1; k >= 0; k--)
            {
                res[k] *= 2;
                res.push_back(res[k] + 1);
            }
        }
        
        return res;
    }
};
