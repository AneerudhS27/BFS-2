#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
We do a level order traversal using a queue, checking each level for x and y.
If they are siblings (same parent), we return false immediately.
If both found on the same level but not siblings, return true, otherwise false.
*/
class Solution{
public:
    bool isCousins(TreeNode* root, int x, int y){
        queue<TreeNode*> q;
        q.push(root);
        bool x_found = false, y_found = false;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front(); q.pop();

                if(curr->val == x) x_found = true;
                if(curr->val == y) y_found = true;

                if(curr->left != nullptr && curr->right != nullptr){
                    if(curr->left->val == x && curr->right->val == y) return false;
                    if(curr->left->val == y && curr->right->val == x) return false;
                }

                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            if(x_found && y_found) return true;
            if(x_found || y_found) return false;
        }
        return true;
    }
};
