//
//  559 Maximum Depth of N-ary Tree.cpp
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

// bottom_up
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        
        int depth = 0;
        for (Node *node : root->children) {
            depth = max(maxDepth(node), depth);
        }
        
        return depth + 1;
    }
};

// top_down
class Solution1 {
public:
    int maxDepth(Node* root) {
        int answer = 0;
        max_depth_core(root, 1, answer);
        return answer;
    }
    
    void max_depth_core(Node *root, int depth, int &answer) {
        if (!root) {
            return;
        }
        
        if (root->children.empty()) {
            answer = max(answer, depth);
            return;
        }
        
        for (Node *node : root->children) {
            max_depth_core(node, depth + 1, answer);
        }
    }
};
