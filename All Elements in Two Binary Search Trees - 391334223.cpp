/*
Author : Poojan Thaker 
Problem name : All Elements in Two Binary Search Trees
Runtime : 232 ms 
Memory : 87.1 MB
Problem link : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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
        void DFS(TreeNode*root,vector<int>& ele){
        if(!root)return;
                DFS(root->left,ele);
        ele.push_back(root->val);
        DFS(root->right,ele);
    }
            vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ele1;
        vector<int> ele2;
                DFS(root1,ele1);
        DFS(root2,ele2);
                vector<int> ans;
                int i=0;
        int j=0;
        while(i<ele1.size()&&j<ele2.size()){
            if(ele1[i]<ele2[j]){
                ans.push_back(ele1[i++]);
            }
            else{
                ans.push_back(ele2[j++]);
            }
        }
                while(i<ele1.size()){
            ans.push_back(ele1[i++]);
        }
         while(j<ele2.size()){
            ans.push_back(ele2[j++]);
        }
                return ans;
    }
};
