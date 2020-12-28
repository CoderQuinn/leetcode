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

class Solution0 {
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
class Solution {
public:
    bool isHappy(int n) {
        int fast = get(n), slow = n;
        while(fast != slow) {
            fast = get(get(fast));
            slow = get(slow);
        }
        return fast == 1;
    }

    int get(int x) {
        int res = 0;
        while(x) {
            res += (x % 10) * (x % 10);
            x /= 10;
        }
        return res;
    }
};
