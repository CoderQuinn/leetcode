//
//  589 N-ary Tree Preorder Traversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// recursively
class Solution {
public:
    vector<int> result_vector;
    vector<int> preorder(Node* root) {
        if (root) {
            result_vector.push_back(root->val);
            for (Node *node : root->children) {
                preorder(node);
            }
        }

        return result_vector;
    }
};

// iteratively
class Solution1 {
public:
    vector<int> preorder(Node* root) {
        vector<int> output;
        if (!root) return output;
        
        stack<Node *> node_stack;
        node_stack.push(root);
        
        Node *curr = nullptr;
        while (!node_stack.empty()) {
            curr = node_stack.top();
            output.push_back(curr->val);
            node_stack.pop();
            if (!curr->children.empty()) {
                size_t size = curr->children.size();
                for (long i = size - 1; i >= 0; --i) {
                    Node *node = curr->children[i];
                    if (node) {
                        node_stack.push(node);
                    }
                }
            }
        }
        
        return output;
    }
};
