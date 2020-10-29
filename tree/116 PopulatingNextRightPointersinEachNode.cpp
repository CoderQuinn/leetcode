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
        if(!root) return nullptr;
        Node *cur = root;
        while(cur)
        {
            for(auto p = cur; p != nullptr; p = p->next)
            {
                if(p->left)
                {
                    p->left->next = p->right;
                    if(p->next)
                        p->right->next = p->next->left;
                }
            }
            cur = cur->left;
        }
        return root;
    }
};

class Solution1 { // 完美二叉树，有左子树就必定有右子树
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

class Solution2 {
public:
    Node* connect(Node* root) {
        return dfs(root, NULL);
    }

    Node *dfs(Node *root, Node *next)
    {
        if(!root) return NULL;
        root->next = next;
        dfs(root->left, root->right);
        dfs(root->right, next ? next->left : NULL);
        return root;
    }
};
