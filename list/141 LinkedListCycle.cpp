//
//  LinkedListCycle.cpp
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> hash;
        for(auto p = head; p; p = p->next) {
            if(hash.count(p)) {
                return true;
            }
            hash.insert(p);
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fast = head, slow = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast && slow == fast) {
                return true;
            }
        }
        return false;
    }
};
