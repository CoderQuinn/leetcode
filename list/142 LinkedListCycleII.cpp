//
//  LinkedListCycleII.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include <unordered_set>
using namespace std;

class Solution0 {
public:
    // 思路：若链表存在环，则set中必能查找到环的第一个节点
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> hash;
        for(auto p = head; p; p = p->next) {
            if(hash.count(p)) {
                return p;
            }
            hash.insert(p);
        }
        return nullptr;
    }
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        auto fast = head, slow = head;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            else
                return nullptr;

            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
