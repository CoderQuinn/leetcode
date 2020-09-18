//
//  26 Remove Duplicates from Sorted Array.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int j = 0;
       for(int i = 0; i < nums.size(); i++)
       {
           if(i == 0 || nums[i] != nums[i - 1]) {
               nums[j++] = nums[i];
           }
       }
       return j;
    }
};
