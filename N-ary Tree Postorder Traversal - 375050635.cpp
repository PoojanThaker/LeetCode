/*
Author : Poojan Thaker 
Problem name : N-ary Tree Postorder Traversal
Runtime : 36 ms 
Memory : 11.1 MB
Problem link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/
*/
/*
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
*/
class Solution {
public:
    void post(Node*root,vector<int>& ans){
    if(!root)return;
    for(auto x:root->children){
        post(x,ans);
    }
     ans.push_back(root->val);
}
    vector<int> postorder(Node* root) {
        vector<int> ans;
        post(root,ans);
        return ans;
    }
};
