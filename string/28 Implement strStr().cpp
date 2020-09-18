//
//  28 Implement strStr().cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

// Brute force, native string matcher;
// Time complexity: O((n-m+1) * m), sapce complexity: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if(m == 0) return 0;

        int s = n - m;
        if(s < 0) return -1;

        for(int i = 0; i <= s; i++)
        {
            int j = 0, k = 0;
            while(haystack[i + k] == needle[j] && j < m) {
                k++;
                j++;
            };

            if(j == m) return i;
        }

        return -1;
    }
};

// kmp matcher, time complexity: O(n + m), sapce complexity: O(m)
class Solution1 {
public:
    vector<int> next;
    void compute_prefix(string p)
    {
        int length = p.length() - 1;
        next[1] = 0;
        for(int i = 2, j = 0; i <= length; i++)
        {
            while(j > 0 && p[i] != p[j + 1])
            {
                j = next[j];
            }

            if(p[i] == p[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m == 0) return 0;
        if(n < m) return -1;
        
        next.resize(m + 1);

        haystack.insert(haystack.begin(), ' ');
        needle.insert(needle.begin(), ' ');
        
        compute_prefix(needle);
        

        for(int i = 1, j = 0; i <= n; i++)
        {
            while(j > 0 && haystack[i] != needle[j + 1])
            {
                j = next[j];
            }

            if(haystack[i] == needle[j + 1]) {
                j++;
            }

            if(j == m) {
                return i - m;
            }
        }

        return -1;
    }
};
