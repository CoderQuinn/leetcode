//
//  88 Merge Sorted Array.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while(j >= 0) nums1[k--] = nums2[j--];
        
    }
};

class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        vector<int> tmp(n + m, 0);
        for(; i < m && j < n;)
        {
            if(nums1[i] <= nums2[j])
                tmp[k++] = nums1[i++];
            else
                tmp[k++] = nums2[j++];
        }
        while(i < m) tmp[k++] = nums1[i++];
        while(j < n) tmp[k++] = nums2[j++];
        nums1 = tmp;
    }
};
