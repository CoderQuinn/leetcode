//
//  73 Set Matrix Zeroes.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/19.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return;
        int r0 = 1, c0 = 1; // r0第0列，c0第0行

        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            if (!matrix[i][0])
            {
                r0 = 0;
                break;
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (!matrix[0][j])
            {
                c0 = 0;
                break;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!matrix[j][i])
                {
                    matrix[0][i] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {

            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < m; j++)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < m; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < n; i++)
                    matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!r0)
            {
                matrix[i][0] = 0;
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (!c0)
            {
                matrix[0][j] = 0;
            }
        }
    }
};
