//
//  PopulatingNextRightPointersinEachNode.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node *> node_queue;
        node_queue.push(root);
        
        while (!node_queue.empty()) {
            auto size = node_queue.size();
            Node *prev = nullptr;
            for (int i = 0; i < size; ++i) {
                Node *curr = node_queue.front();
                node_queue.pop();
                if (prev) {
                    prev->next = curr;
                }
                
                if (curr->left) {
                    node_queue.push(curr->left);
                }
                
                if (curr->right) {
                    node_queue.push(curr->right);
                }
                
                prev = curr;
            }
            prev->next = nullptr;
        }
        
        
        return root;
    }
};

class Solution1
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        Node *head = new Node(-1), *tail = head;
        Node *cur = root;
        while (cur)
        {
            head->next = nullptr;
            tail = head;
            for (auto p = cur; p; p = p->next)
            {
                if (p->left)
                {
                    tail->next = p->left;
                    tail = tail->next;
                }
                if (p->right)
                {
                    tail->next = p->right;
                    tail = tail->next;
                }
            }
            cur = head->next;
        }
        return root;
    }
};
