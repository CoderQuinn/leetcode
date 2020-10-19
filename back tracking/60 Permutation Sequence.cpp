//
//  60 Permutation Sequence.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        for(int i = 1; i <= n; i++) res += to_string(i);
        for(int i = 0; i < k -1; i++)
        {
            next_permutation(res.begin(), res.end());
        }
        return res;
    }
};

class Solution1 {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<bool> state(n + 1);
        for(int i = 1; i <= n; i++)
        {
            int fact = 1;
            for(int j = 1; j <= n - i; j++)
                fact *= j;
            
            for(int j = 1; j <= n; j++)
            {
                if(!state[j])
                {
                    if(fact < k)
                        k -= fact;
                    else
                    {
                        res += to_string(j);
                        state[j] = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
