//
//  FindSmallestLetterGreaterThanTarget.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using std::vector;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto c : letters) {
            if (c > target) {
                return c;
            }
        }
        return letters[0];
    }
};

class Solution1 {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // right = size，说明没有比target小的元素
        return letters[left % letters.size()];
    }
};
