//
//  4 Median of Two Sorted Arrays.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto n = nums1.size() + nums2.size();
        double result = 0;
        if (n & 1) {
            result = find_kth(nums1, nums2,  int(n / 2) + 1);
        } else {
            int left = find_kth(nums1, nums2,  int(n / 2));
            int right = find_kth(nums1, nums2,  int(n / 2) + 1);
            result = (left + right) / 2.0;
        }
        return result;
    }
    
    // recurision
    int find_kth(vector<int>& nums1, int left1, vector<int>& nums2, int left2, int k) {

        if (left1 == nums1.size()) {
            return nums2[left2 + k -1];
        } else if (left2 == nums2.size()) {
            return nums1[left1 + k -1];
        }
        
        if (k == 1) {
            return min(nums1[left1], nums2[left2]);
        }
        

        int k1_half = min(left1 + k / 2, (int)nums1.size());
        int k2_half = min(left2 + k / 2, (int)nums2.size());
        
        if (nums1[k1_half - 1] < nums2[k2_half - 1]) {
            return find_kth(nums1, k1_half, nums2, left2, k - (k1_half - left1));
        } else {
            return find_kth(nums1, left1, nums2, k2_half, k - (k2_half - left2));
        }
    }
    
    int find_kth(vector<int>& nums1, vector<int>& nums2, int k) {
        int index1 = 0;
        auto size1 = nums1.size();
        int index2 = 0;
        auto size2 = nums2.size();
        
        while (true) {
            
            if (index1 == size1) {
                return nums2[index2 + k - 1];
            } else if (index2 == size2) {
                return nums1[index1 + k - 1];
            }
            
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            
            int new_index1 = min(index1 + k / 2 - 1, int(nums1.size() - 1));
            int new_index2 = min(index2 + k / 2 - 1, int(nums2.size() - 1));
            if (nums1[new_index1] <= nums2[new_index2]) {
                k -= (new_index1 - index1 + 1);
                index1 = new_index1 + 1;
            } else {
                k -= (new_index2 - index2 + 1);
                index2 = new_index2 + 1;
            }
        }
    }
};
