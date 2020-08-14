//
//  771 Jewels and Stones.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int numJewelsInStones(string J, string S) {
        unordered_set<char> hash_set;
        for (auto ch : J) {
            hash_set.insert(ch);
        }
        
        int sum = 0;
        for (auto ch : S) {
            if (hash_set.count(ch) > 0) {
                sum++;
            }
        }
        
        return sum;
    }
};
