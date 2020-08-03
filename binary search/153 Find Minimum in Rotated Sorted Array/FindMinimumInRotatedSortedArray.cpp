//
//  FindMinimumInRotatedSortedArray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//
#include <vector>
#include <climits>
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (nums[right] < nums[mid]) { // 右边无序
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return nums[left];
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
