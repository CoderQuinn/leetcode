//
//  315 Count of Smaller Numbers After Self.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/17.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 蛮力枚举法, 时间复杂度：O(n²)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    result[i]++;
                }
            }
        }
        
        return result;
    }
    
};

// 分而治之，归并求解
class Solution1 {
public:
    vector<int> tmp_arr;
    vector<int> tmp_index;
    vector<int> answer;
    vector<int> index;
    
    vector<int> countSmaller(vector<int>& nums) {

        auto size = nums.size();
        
        answer.assign(size, 0);
        tmp_arr.assign(size, 0);
        tmp_index.assign(size, 0);
        
        for (int i = 0; i < size; ++i) {
            index.push_back(i);
        }
        count_smaller_helper(nums, 0, int(size - 1));
        return answer;
    }
    
    void count_smaller_helper(vector<int>& nums, int left, int right) {
        
        if (left < right) {
            int mid = left + ((right - left) >> 1) ;
            count_smaller_helper(nums, left, mid);
            count_smaller_helper(nums, mid + 1, right);
            merge_pass(nums, left, mid, right);
        }
    }
    
    void merge_pass(vector<int>& arr, int left, int mid, int right) {
        for (int i = left; i <= right; ++i) {
            tmp_index[i] = index[i];
            tmp_arr[i] = arr[i];
        }
        
        int i = left;
        int j = mid + 1;
        int k = left;
        
        while (i <= mid && j <= right) {
            if (tmp_arr[i] <= tmp_arr[j]) {
                answer[tmp_index[i]] += (j - mid - 1);
                index[k] = tmp_index[i];
                arr[k++] = tmp_arr[i++];
            } else {
                index[k] = tmp_index[j];
                arr[k++] = tmp_arr[j++];
            }
        }
        
        while (i <= mid) {
            answer[tmp_index[i]] += (j - mid - 1);
            index[k] = tmp_index[i];
            arr[k++] = tmp_arr[i++];
        }
        
        while (j <= right) {
            index[k] = tmp_index[j];
            arr[k++] = tmp_arr[j++];
        }
    }
};
