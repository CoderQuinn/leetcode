//
//  299 Bulls and Cows.cpp
//  Leetcode
//
//  Created by Quinn on 2021/4/8.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> hash;
        for(auto &v : secret) hash[v]++;
        int bulls = 0, sum = 0;
        for(auto &v : guess)
        {
            if(hash[v]) sum++, hash[v]--;
        }

        for(int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i]) bulls++;
        }

        return to_string(bulls) + 'A' + to_string(sum - bulls) + 'B';
    }
};
