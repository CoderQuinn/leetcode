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
