//
//  Kth Largest Element in a Stream.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/8.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <queue>
using namespace::std;

class KthLargest {
public:
    struct MyTreeNode {
        int val;
        int cnt;
        MyTreeNode *left;
        MyTreeNode *right;
        MyTreeNode(int x) : val(x), cnt(1), left(NULL), right(NULL) {}
        
    };
    
    KthLargest(int k, vector<int>& nums) {
        K_ = k;
        root_ = nullptr;
        for (auto num : nums) {
            root_ = insertIntoBST(num, root_);
        }
    }
    
    int add(int val) {
        root_ = insertIntoBST(val, root_);
        return find_nth_largest(K_, root_);
    }
    
    int find_nth_largest(int n, MyTreeNode *root) {
        int count = 1;
        if (root->right) {
            count += root->right->cnt;
        }
        
        if (count == n) {
            return root->val;
        } else if(count > n) {
            return find_nth_largest(n, root->right);
        } else {
            return find_nth_largest(n - count, root->left);
        }
    }
    
    MyTreeNode* insertIntoBST(int val, MyTreeNode *root) {
        if (!root) {
            root = new MyTreeNode(val);
            return root;
        }
        
        MyTreeNode *curr = root;
        while (curr) {
            if (curr->val < val) {
                curr->cnt += 1;
                if (curr->right) {
                    curr = curr->right;
                } else {
                    curr->right = new MyTreeNode(val);
                    break;
                }
                
            } else {
                curr->cnt += 1;
                if (curr->left) {
                    curr = curr->left;
                } else {
                    curr->left = new MyTreeNode(val);
                    break;
                }
            }
        }
        
        return root;
    }
private:
    int K_;
    MyTreeNode *root_;
};

// use deap
class KthLargest1 {
public:
    KthLargest1(int k, vector<int>& nums) {
        K_ = k;
        for (auto num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (val_heap_.size() < K_) {
            val_heap_.push(val);
        } else if(val > val_heap_.top()) {
            val_heap_.pop();
            val_heap_.push(val);
        }
        return val_heap_.top();
    }
    
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> val_heap_;
    int K_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
