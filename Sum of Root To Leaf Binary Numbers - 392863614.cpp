/*
Author : Poojan Thaker 
Problem name : Sum of Root To Leaf Binary Numbers
Runtime : 8 ms 
Memory : 19.7 MB
Problem link : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
        int string_to_num(string s){
        int current=0;
        for(int i=0;i<s.length();i++){
            current*=2;
            current+=s[i]-'0';
        }
        return current;
    }
        void DFS(TreeNode*root,string current){
        if(!root)return;
                current.push_back(root->val+'0');
                if(!root->right&&!root->left){
            ans+=string_to_num(current);
        }
                DFS(root->left,current);
        DFS(root->right,current);
            }
                int sumRootToLeaf(TreeNode* root) {
        ans=0;
        DFS(root,"");
        return ans;
    }
};
