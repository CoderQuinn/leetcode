//
//  912 Sort an Array.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/17.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> tmp_nums;
    vector<int> sortArray(vector<int>& nums) {
        long size = nums.size();
        tmp_nums.assign(size, 0);
        merge_sort(nums, 0, size - 1);
        return nums;
    }
    
    void merge_sort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            merge_sort(nums, left, mid);
            merge_sort(nums, mid + 1, right);
            merge_pass(nums, left, mid, right);
        }
    }
    
    void merge_pass(vector<int>& nums, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            tmp_nums[i] = nums[i];
        }
        
        int i = left;
        int j = mid + 1;
        int k = left;
        while (i <= mid && j <= right) {
            if (tmp_nums[i] <= tmp_nums[j]) {
                nums[k++] = tmp_nums[i++];
            } else {
                nums[k++] = tmp_nums[j++];
            }
        }
        
        while (i <= mid) {
            nums[k++] = tmp_nums[i++];
        }
        
        while (j <= right) {
            nums[k++] = tmp_nums[j++];
        }
    }
};
