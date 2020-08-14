//
//  454 4Sum II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hash_map;
        int answer = 0;
        for (auto a : A) {
            for (auto b : B) {
                hash_map[a + b] += 1;
            }
        }
        
        for (auto c : C) {
            for (auto d : D) {
                auto it = hash_map.find(-c-d);
                if (it != hash_map.end()) {
                    answer += it->second;
                }
            }
        }
        return answer;
    }
};
