//
//  FindKClosestElements.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <cstdio>
using std::vector;

/*
 *
 */
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result_vector;
        int left = 0;
        int right = arr.size() - 1;
        
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                left = mid;
                right = left + 1;
            } else if (arr[mid] < x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        if (abs(arr[left]- x) <= abs(arr[right] - x)) {
            right = left;
        } else {
            left = right;
        }
        
        int count = k - 1;
        while (count > 0) {
            if (left == 0) {
                ++right;
            } else if (right == arr.size() - 1) {
                --left;
            } else {
                if (abs(arr[left - 1] - x) <= abs(arr[right + 1] - x)) {
                    --left;
                } else {
                    ++right;
                }
            }
            --count;
        }
        for (int i = left; i <= right; i++) {
            result_vector.push_back(arr[i]);
        }
        
        return result_vector;
    }
};

// 模板3
/*
 int binarySearch(vector<int>& nums, int target){
     if (nums.size() == 0)
         return -1;

     int left = 0, right = nums.size() - 1;
     while (left + 1 < right){
         // Prevent (left + right) overflow
         int mid = left + (right - left) / 2;
         if (nums[mid] == target) {
             return mid;
         } else if (nums[mid] < target) {
             left = mid;
         } else {
             right = mid;
         }
     }

     // Post-processing:
     // End Condition: left + 1 == right
     if(nums[left] == target) return left;
     if(nums[right] == target) return right;
     return -1;
 }
 
 初始条件：left = 0, right = length-1
 终止：left + 1 == right
 向左查找：right = mid
 向右查找：left = mid

 */
