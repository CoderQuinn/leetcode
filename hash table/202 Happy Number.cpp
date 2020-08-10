//
//  202 Happy Number.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/10.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash_set;
        while (n != 1 && hash_set.count(n) <= 0) {
            hash_set.insert(n);
            n = get_next(n);
        }
        return n == 1;
    }
    
    int get_next(int n) {
        int result = 0;
        while (n > 0) {
            int left = n % 10;
            n /= 10;
            result += left * left;
        }
        return result;
    }
};

// 快慢指针
class Solution1 {
public:
    bool isHappy(int n) {
        int slow = get_next(n);
        int fast = get_next(slow);
        while (slow != fast) {
            slow = get_next(slow);
            fast = get_next(get_next(fast));
        }
        return slow == 1;
    }
    
    int get_next(int n) {
        int result = 0;
        while (n > 0) {
            int left = n % 10;
            n /= 10;
            result += left * left;
        }
        return result;
    }
};
