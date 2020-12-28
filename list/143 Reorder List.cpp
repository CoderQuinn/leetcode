//
//  143 Reorder List.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/3.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
using namespace std;

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head)
            return;
        
        int n = 0;
        for (auto p = head; p; p = p->next)
        {
            n++;
        }
        
        auto mid = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i++)
        {
            mid = mid->next;
        }
        
        auto a = mid, b = a->next;
        for (int i = 0; i < n / 2; i++)
        {
            auto tmp = b->next;
            b->next = a;
            a = b;
            b = tmp;
        }
        
        auto p = head, q = a;
        for (int i = 0; i < n / 2; i++)
        {
            auto tmp = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = tmp;
        }
        
        if (n % 2)
        {
            mid->next = nullptr;
        }
        else
        {
            mid->next->next = nullptr;
        }
    }
};
