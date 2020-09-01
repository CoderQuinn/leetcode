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
        auto n = haystack.size();
        auto m = needle.size();
        
        if (m == 0) return 0;
        if (n < m) return -1;

        int ret = -1;
        for (int i = 0, j = 0; i <= n - m; i++) {
            j = 0;
            
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            
            if (j == m) {
                ret = i;
                break;
            }
        }
        
        return ret;
    }
};

// kmp matcher, time complexity: O(n + m), sapce complexity: O(m)
class Solution1 {
public:
    void compute_prefix(string &p, vector<int> &next) {
        int m = p.size() - 1; // O(m)
        next[1] = 0;
        int j = 0;
        for (int i = 2; i <= m; i++) { // O(m)
            while (j > 0 && p[j + 1] != p[i]) {
                j = next[j];
            }
            
            if (p[j + 1] == p[i]) {
                j++;
            }
            next[i] = j;
 
        }
    }
    
    int strStr(string t, string p) {
        if (p.empty()) return 0;
        
        int n = (int)t.size();
        int m = (int)p.size();

        t = ' ' + t; // for i=1 to n
        p = ' ' + p;
        
        vector<int> next(m + 1);
        compute_prefix(p, next);
        
        int ret = -1;
        for (int i = 1, j = 0; i <= n; i++) {
            while (j > 0 && p[j + 1] != t[i]) { // pattern string backtracking
                j = next[j];
            }
            
            if (p[j + 1] == t[i]) {
                j++;
            }
            
            if (j == m) {
                ret = i - m;
                // j = next[j]; // go on searching next match substring
                break;
            }
        }
        
        return ret;
    }
};
