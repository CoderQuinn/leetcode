//
//  PalindromeLinkedList.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include <vector>

class Solution0 {
public:
    bool isPalindrome(ListNode* head) {
        // 思路1. 利用数组的特性：时间复杂度O(n)，空间复杂度O(n)
        std::vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < vec.size() / 2; ++i) {
            if (vec[i] != vec[vec.size() - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
    
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        int n = 0;
        for (auto p = head; p; p = p->next)
        {
            n++;
        }
        if (n <= 1)
            return true;

        int half = n / 2;
        auto a = head;
        for (int i = 0; i < n - half; i++)
        {
            a = a->next;
        }

        auto b = a->next;
        for (int i = 0; i < half - 1; i++)
        {
            auto tmp = b->next;
            b->next = a;
            a = b;
            b = tmp;
        }

        auto p = head, q = a;
        bool success = true;
        for (int i = 0; i < half; i++)
        {
            if (p->val != q->val)
            {
                success = false;
                break;
            }
            p = p->next;
            q = q->next;
        }

        auto tail = a;
        b = a->next;
        for (int i = 0; i < half - 1; i++)
        {
            auto tmp = b->next;
            b->next = a;
            a = b;
            b = tmp;
        }
        tail->next = nullptr;

        return success;
    }
};
