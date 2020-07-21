//
//  FlattenaMultilevelDoublyLinkedList.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include <stack>
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev; // 相当于指向父结点
    Node* next; // 指向右子树
    Node* child; // 指向左子树
};
*/

// 递归解决
class Solution1 {
private:
    Node *flattenDFS(Node *prev, Node *curr) {
        if (!curr) return prev;
        
        curr->prev = prev;
        prev->next = curr;
        
        Node *curr_next = curr->next; // 下一步会破坏curr的next域，需提前暂存
        Node *curr_next_prev = flattenDFS(curr, curr->child); // 连接右子树的prev
        curr->child = nullptr; // 扁平化结果后，child指向为空
        
        return flattenDFS(curr_next_prev, curr_next);
    }
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node pseudo_node;
        Node *prev = &pseudo_node;
        
        flattenDFS(prev, head);
        
        prev = pseudo_node.next;
        prev->prev = nullptr;
        
        return prev;
    }
};

// 栈的迭代解决
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node pseudo_node;
        Node *prev = &pseudo_node;
        Node *curr = nullptr;
        
        std::stack<Node *> stack;
        stack.push(head);
        
        while (!stack.empty()) {
            curr = stack.top();
            stack.pop();
            prev->next = curr;
            curr->prev = prev;
            
            if (curr->next) { // 右子树先入栈
                stack.push(curr->next);
            }
            
            if (curr->child) { // 左子树入栈
                stack.push(curr->child);
                curr->child = nullptr; // 扁平化后，child指向为空
            }
            
            prev = curr;
        }
        
        // 去掉伪头结点
        curr = pseudo_node.next;
        curr->prev = nullptr;

        return curr;
    }
};
