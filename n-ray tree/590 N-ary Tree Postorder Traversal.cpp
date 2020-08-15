//
//  590 N-ary Tree Postorder Traversal.cpp
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
    vector<int> postorder(Node* root) {
        if (root) {
            for (Node *node : root->children) {
                postorder(node);
            }
            result_vector.push_back(root->val);
        }

        return result_vector;
    }
};

// iteratively
class Solution1 {
public:
    vector<int> postorder(Node* root) {
        vector<int> output;
        if (!root) return output;
        
        stack<Node *> node_stack;
      
        node_stack.push(root);
        Node *last_visited = nullptr;
        Node *curr = root;
        while (!node_stack.empty()) {
            while (curr) {
                if (!curr->children.empty()) {
                    size_t size = curr->children.size();
                    vector<Node*> &vec = curr->children;
                    for (long i = size - 1; i >= 0; --i) {
                        curr = vec[i];
                        if (curr) {
                            node_stack.push(curr);
                        }
                    }
                } else {
                    curr = nullptr;
                }
            }
            
            curr = node_stack.top();
            if (curr->children.empty() || last_visited == curr->children.back()) {
                last_visited = curr;
                output.push_back(last_visited->val);
                node_stack.pop();
                curr = nullptr;
            }

        }
        return output;
    }
};
