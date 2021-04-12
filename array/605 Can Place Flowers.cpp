//
//  605 Can Place Flowers.cpp
//  Leetcode
//
//  Created by Quinn on 2021/1/2.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (!n)
            return true;
        
        int res = 0;
        for (int i = 0, j; i < flowerbed.size(); i++)
        {
            if (flowerbed[i])
                continue;
            
            j = i;
            while (j < flowerbed.size() && flowerbed[j] == 0)
            {
                j++;
            }
            
            int k = j - 1 - i;
            if (!i)
                k++; // 左边界
            if (j == flowerbed.size())
                k++; // 右边界
            res += k / 2;
            if (res >= n)
                return true;
            i = j;
        }
        
        return false;
    }
};
