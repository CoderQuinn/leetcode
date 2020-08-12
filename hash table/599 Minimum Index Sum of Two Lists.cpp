//
//  599 Minimum Index Sum of Two Lists.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/11.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*  提示:

    两个列表的长度范围都在 [1, 1000]内。
    两个列表中的字符串的长度将在[1，30]的范围内。
    下标从0开始，到列表的长度减1。
    两个列表都没有重复的元素。
*/
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.size() > list2.size()) {
            return findRestaurant(list2, list1);
        }
        
        unordered_map<string, long> hash_map;
        
        vector<string> string_vector;
        for (long i = 0; i < list2.size(); ++i) {
            hash_map[list2[i]] = i;
        }
        
        long min_index = LONG_MAX;
        for (long i = 0; i < list1.size(); ++i) {
            if (hash_map.count(list1[i])) {
                long index = i + hash_map[list1[i]];
                if (index < min_index) {
                    string_vector.clear();
                    min_index = index;
                    string_vector.push_back(list1[i]);
                } else if(index == min_index) {
                    string_vector.push_back(list1[i]);
                }
            }
        }
        return string_vector;
    }
};
