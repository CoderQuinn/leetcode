//
//  GuessNumberHigherorLower.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/2.
//  Copyright © 2020 Quinn. All rights reserved.
//

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return          -1 if num is lower than the guess number
 *                  1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);
            if (result == 0) {
                return mid;
            } else if(result == 1) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};

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
