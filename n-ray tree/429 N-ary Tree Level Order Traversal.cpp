//
//  429 N-ary Tree Level Order Traversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <queue>
using namespace::std;


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


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result_vec;
        if (!root) return result_vec;
        
        queue<Node*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            
            size_t size = node_queue.size();
            vector<int> curr_level_vec;
            for (int i = 0; i < size; ++i) {
                Node *curr = node_queue.front();
                curr_level_vec.push_back(curr->val);
                node_queue.pop();
                if (!curr->children.empty()) {
                    for (Node *node : curr->children) {
                        if (node) {
                            node_queue.push(node);
                        }
                    }
                }
            }
            result_vec.push_back(curr_level_vec);
        }
        
        return result_vec;
    }
};
