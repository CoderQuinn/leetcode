//
//  Intersection of Two Linked Lists.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/11.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include <set>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        auto p = headA, q = headB;
        while (p != q)
        {
            if (p)
                p = p->next;
            else
                p = headB;

            if (q)
                q = q->next;
            else
                q = headA;
        }
        return p;
    }
};

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
      /* 方法二: 哈希表法
       遍历链表 A 并将每个结点的地址/引用存储在哈希表中。然后检查链表 B 中的每一个结点 b是否在哈希表中。若在，则为相交结点。

        复杂度分析

        时间复杂度 : O(m+n)O(m+n)。
        空间复杂度 : O(m)O(m) 或 O(n)O(n)。
       */
        if (!headA || !headB) {
            return nullptr;
        }

        std::set<ListNode *> node_set;
        while (headB) {
            node_set.insert(headB);
            headB = headB->next;
        }

        while (headA) {
            if (node_set.find(headA) != node_set.end()) {
                return headA;
            }
            headA = headA->next;
        }

        return nullptr;
        
    }
};
