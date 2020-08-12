//
//  652 Find Duplicate Subtrees.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<string, int> hash_map;
    vector<TreeNode*> result_vec;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return result_vec;
    }
    
    string helper(TreeNode *node) {
        if (!node) return "#";
        
        string node_key = to_string(node->val) + ',' + helper(node->left) + ',' + helper(node->right);
        
        if (hash_map.count(node_key) > 0) {
            hash_map[node_key] += 1;
        } else {
            hash_map[node_key] = 1;
        }
        
        if (hash_map[node_key] == 2) {
            result_vec.push_back(node);
        }
        
        return node_key;
    }
};

class Solution1 {
public:
    int node_tag;
    unordered_map<string, pair<int, int>> hash_map;
    vector<TreeNode*> result_vec;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        node_tag = 1;
        find_duplicate_subtrees_helper(root);
        return result_vec;
    }
    
    int find_duplicate_subtrees_helper(TreeNode *node) {
        if (!node) return 0;
        
        string node_key = to_string(node->val) + ',' + to_string(find_duplicate_subtrees_helper(node->left)) + ',' + to_string(find_duplicate_subtrees_helper(node->right));
        
        if (hash_map.count(node_key) <= 0) { // 第一次访问子树
            hash_map[node_key] = make_pair(node_tag, 1);
            return node_tag++;
        }
        
        pair<int, int> &pair = hash_map[node_key];
        pair.second++;

        if (pair.second == 2) { // 只添加一次相同的子树，避免出现三个相同值的叶结点重复添加
            result_vec.push_back(node);
        }
        
        return pair.first;
    }
};

