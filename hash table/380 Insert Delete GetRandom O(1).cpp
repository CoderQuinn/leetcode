//
//  380 Insert Delete GetRandom O(1).cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/14.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, long> hash_map;
    vector<int> data_vec;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash_map.count(val) > 0) {
            return false;
        }
        
        hash_map[val] = data_vec.size();
        data_vec.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash_map.count(val) <= 0) {
            return false;
        }
        long index = hash_map[val];
        data_vec[index] = data_vec.back();
        hash_map[data_vec.back()] = index;
        data_vec.pop_back();
        hash_map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int random = rand() % data_vec.size();
        return data_vec[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
