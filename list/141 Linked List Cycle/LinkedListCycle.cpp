//
//  LinkedListCycle.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include <set>

class Solution1 {
public:
    bool hasCycle(ListNode *head) {

        // 方法1思路：若链表存在环，则set中必能查找到环的节点
        std::set<ListNode *> node_set;
        while (head) {
            if (node_set.find(head) != node_set.end()) {
                return true;
            }
            node_set.insert(head);
            head = head->next;
        }
        return false;

    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        // 方法2思路：快慢指针在有环的情况下，必能相遇
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast && slow && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow && fast != nullptr) {
                return true;
            }
        }
        return false;
    }
};
