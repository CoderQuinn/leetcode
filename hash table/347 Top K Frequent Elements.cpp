//
//  347 Top K Frequent Elements.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/14.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <utility>      // std::pai
#include <unordered_map>
#include <queue>          // std::priority_queue
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator() ( pair<int, int> a, pair<int, int> b ){
            return a.second > b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> hash_map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> deap;
        
        for (auto num: nums) {
            hash_map[num]++;
        }
        
        for (auto pair : hash_map) {
            if (deap.size() < k) {
                deap.push(pair);
            } else {
                auto top_pair = deap.top();
                if (top_pair.second < pair.second) {
                    deap.pop();
                    deap.push(pair);
                }
            }
        }
        
        while (!deap.empty()) {
            auto top_pair = deap.top();
            result.push_back(top_pair.first);
            deap.pop();
        }

        return result;
    }
};
