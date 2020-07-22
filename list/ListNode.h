//
//  ListNode.h
//  Leetcode
//
//  Created by Quinn on 2020/7/11.
//  Copyright © 2020 Quinn. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

#include <stdio.h>

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Node {
public:
    int val;
    Node* prev; // 相当于指向父结点
    Node* next; // 指向右子树
    Node* child; // 指向左子树
};

#endif /* ListNode_h */
