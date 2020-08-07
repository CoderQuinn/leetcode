//
//  LinkedListCycleII.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"

#include "ListNode.h"
#include <set>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // 方法1思路：若链表存在环，则set中必能查找到环的第一个节点
        std::set<ListNode *> node_set;
        while (head) {
            if (node_set.find(head) != node_set.end()) {
                return head;
            }
            node_set.insert(head);
            head = head->next;
        }
 
        return NULL;
    }
};

class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {

        // 方法2思路：快慢节点在有环的情况下，必能相遇，找到相遇点能很容易找到第一个节点
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = nullptr;
        
        while (slow && fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                meet = slow;
                break;
            }
        }
        
        if (!meet) return nullptr;
        
        slow = head;
        while (meet && slow) {
            if (meet == slow) {
                return meet;
            }
            meet = meet->next;
            slow = slow->next;
        }
        
        return nullptr;
    }
};
