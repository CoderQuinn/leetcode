//
//  Sqrt(x).cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/2.
//  Copyright © 2020 Quinn. All rights reserved.
//

/* 模板 #1
 int binarySearch(vector<int>& nums, int target){
   if(nums.size() == 0)
     return -1;

   int left = 0, right = nums.size() - 1;
   while(left <= right){
     // Prevent (left + right) overflow
     int mid = left + (right - left) / 2;
     if(nums[mid] == target){ return mid; }
     else if(nums[mid] < target) { left = mid + 1; }
     else { right = mid - 1; }
   }

   // End Condition: left > right
   return -1;
 }
 
 初始条件：left = 0, right = length-1
 终止：left > right
 向左查找：right = mid-1
 向右查找：left = mid+1
 
 */

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while(left <= right){
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            long long result = 1;
            result = result * mid * mid; // prevent int overflow
            if(result == x) {
                return mid;
            }
            else if(result < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};
