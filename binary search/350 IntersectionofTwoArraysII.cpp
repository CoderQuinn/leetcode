//
//  IntersectionofTwoArraysII.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/4.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// using sort
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result_vector;
        if (nums1.empty() || nums2.empty()) return result_vector;
        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        // STL
        std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(result_vector));
        
        return result_vector;
    }
    
};

// using sort
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result_vector;
        if (nums1.empty() || nums2.empty()) return result_vector;
        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int>::size_type left1 = 0, right1 = nums1.size();
        vector<int>::size_type left2 = 0, right2 = nums2.size();
        while (left1 < right1 && left2 < right2)
        {
            if (nums1[left1] < nums2[left2]) {
                ++left1;
            }
            else if (nums1[left1] > nums2[left2]) {
               ++left2;
            }
            else {
                result_vector.push_back(nums1[left1]);
                ++left1;
                ++left2;
            }
        }
        
        return result_vector;
    }
};

class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        vector<int> vector;
        unordered_map<int, int> hash_map;
        for (auto num : nums1) {
            if (hash_map.count(num) > 0) {
                hash_map[num] += 1;
            } else {
                hash_map[num] = 1;
            }
        }
        
        for (auto num : nums2) {
            auto it = hash_map.find(num);
            if (it != hash_map.end()) {
                vector.push_back(num);
                
                hash_map[num] -= 1;
                if (hash_map[num] == 0) {
                    hash_map.erase(it);
                }
            }
        }
        return vector;
    }
};

