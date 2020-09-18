//
//  23 Merge k Sorted Lists.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/12.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include <queue>
using namespace std;

class Solution {
public:
    struct Cmp {
        bool operator() (ListNode *a, ListNode *b) const {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode *, vector<ListNode *>, Cmp> heap;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        for (auto l : lists) {
            if(l) heap.push(l);
        }
        
        while (!heap.empty()) {
            auto top = heap.top();
            heap.pop();
            
            if (top) {
                tail->next = top;
                tail = tail->next;
                
                if (top->next) {
                    heap.push(top->next);
                }
            }
        }
        
        return dummy->next;
    }
};
