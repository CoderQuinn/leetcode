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

class Solution1 {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node *left_most = root;
        
        while (left_most->left) {
            Node *level_node = left_most;
            while (level_node) {
                level_node->left->next = level_node->right;
                if (level_node->next) {
                    level_node->right->next = level_node->next->left;
                }
                level_node = level_node->next;
            }
            left_most = left_most->left;
        }
        
        return root;
    }
};

class Solution2 { // 完美二叉树，有左子树就必定有右子树
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        if (!root->left && !root->right) return root;
        
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }

        root->left = connect(root->left);
        root->right = connect(root->right);
        
        return root;
    }
};

class Solution3 { // 完美二叉树，有左子树就必定有右子树
public:
    Node* connect(Node* root) {
        return connect_core(root, nullptr);
    }
    
    Node *connect_core(Node *current, Node *next) {
        if (!current) return nullptr;
        current->next = next;
        connect_core(current->left, current->right);
        connect_core(current->right, next ? next->left : nullptr);
        
        return current;
    }
};
