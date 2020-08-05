//
//  IntersectionOfTwoArrays.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/4.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result_vector;
        if (nums1.empty() || nums2.empty()) return result_vector;
        
        if (nums1.size() < nums2.size()) {
           return intersection(nums2, nums1);
        }
        
        vector<int> *more_ptr = &nums1;
        vector<int> *less_ptr = &nums2;

        std::sort(more_ptr->begin(), more_ptr->end());
        std::unordered_set<int> set;
        for (auto num : *less_ptr) {
            if (find_enable(*more_ptr, num)) {
                set.insert(num);
            }
        }
        
        for (auto num : set) {
            result_vector.push_back(num);
        }
        
        return result_vector;
    }
    
    bool find_enable(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result_vector;
        if (nums1.empty() || nums2.empty()) return result_vector;
        unordered_set<int> set1;
        for (auto num : nums1) {
            set1.insert(num);
        }
        
        unordered_set<int> set2;
        for (auto num : nums2) {
            set2.insert(num);
        }
        
        if (set1.size() < set2.size()) {
            result_vector = set_intersection(set1, set2);
        } else {
            result_vector = set_intersection(set2, set1);
        }
        
        return result_vector;
    }
    
    vector<int> set_intersection(unordered_set<int>& set1, unordered_set<int>& set2) {
        vector<int> vector;
        for (auto num : set1) {
            if (set2.count(num)) {
                vector.push_back(num);
            }
        }
        
        return vector;
    }
};
