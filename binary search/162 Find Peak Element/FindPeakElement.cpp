//
//  FindPeakElement.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using std::vector;
/*
 * 1. 降序序列 头
 * 2. 升序序列 尾
 * 3. 有峰值序列
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else { // nums[mid] >= nums[mid + 1]
                right = mid;
            }
        }
        return left;
    }
};

/* 模板 #2
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size();
  while(left < right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid; }
  }

  // Post-processing:
  // End Condition: left == right
  if(left != nums.size() && nums[left] == target) return left;
  return -1;
}

初始条件：left = 0, right = length
终止：left == right
向左查找：right = mid
向右查找：left = mid+1

*/

class Solution1 {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                left = mid;
                right = left + 1;
            } else if(nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        int result = nums[right] < nums[left] ? left : right;

        return result;
    }
};

/* 模板 #3
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
