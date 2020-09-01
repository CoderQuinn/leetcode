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

class Solution0 {
public:
    int minArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        if (nums[left] <= nums[right]) return nums[left];
        
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < nums[0]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return nums[left];
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (nums[right] < nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return nums[left];
    }
};

/*
在这个改进版本的二分搜索算法中，我们需要找到这个点。下面是关于变化点的特点：

所有变化点左侧元素 > 数组第一个元素

所有变化点右侧元素 < 数组第一个元素

算法

1. 找到数组的中间元素 mid。

如果中间元素 > 数组第一个元素，我们需要在 mid 右边搜索变化点。

如果中间元素 < 数组第一个元素，我们需要在 mid 左边搜索变化点。

4 5 6 7 2 3

上面的例子中，中间元素 6 比第一个元素 4 大，因此在中间点右侧继续搜索。

当我们找到变化点时停止搜索，当以下条件满足任意一个即可：
nums[mid] > nums[mid + 1]，因此 mid+1 是最小值。

nums[mid - 1] > nums[mid]，因此 mid 是最小值。
*/

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        if (nums[0] < nums[right]) {
            return nums[0];
        }
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            
        }
        
        return -1;
    }
};
