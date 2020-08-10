//
//  220 Contains Duplicate III.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/9.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> BST;
        for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
            long val = (long)nums[i];
            
            auto it = BST.lower_bound(val - t);
            if (it != BST.end() && *it <= val &&  val - *it <= t) {
                return true;
            }
            
            it = BST.lower_bound(val);
            if (it != BST.end() && *it - val <= t) {
                return true;
            }
            
            BST.insert(val);
            
            if (BST.size() > k) {
                BST.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};
