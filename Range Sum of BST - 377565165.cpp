/*
Author : Poojan Thaker 
Problem name : Range Sum of BST
Runtime : 216 ms 
Memory : 64.7 MB
Problem link : https://leetcode.com/problems/range-sum-of-bst/
*/
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
        int ans=0;
        void DFS(TreeNode* root,int L,int R){
        if(!root)return;
                    if(root->val<=R&&root->val>=L){
            ans+=root->val;
        }
                DFS(root->right,L,R);       
        DFS(root->left,L,R);
    }
            int rangeSumBST(TreeNode* root, int L, int R) {
        ans=0;
        DFS(root,L,R);
        return ans;
    }
};
