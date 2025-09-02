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
We do level order traversal using a queue.
For each level, we add the last node's value to the result which gives the right side view of the tree.
For each level, if we add the first node's value to the resul, then it will give the left side view of the tree.
*/
class Solution{
public:
    vector<int> rightView(TreeNode* root){
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        if(root == nullptr) return result;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front(); q.pop();
                if(i == size-1) result.push_back(curr->val);
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
        }
        return result;
    }
};
