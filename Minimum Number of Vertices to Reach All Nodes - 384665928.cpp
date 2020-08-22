/*
Author : Poojan Thaker 
Problem name : Minimum Number of Vertices to Reach All Nodes
Runtime : 1104 ms 
Memory : 106 MB
Problem link : https://leetcode.com/contest/biweekly-contest-33/problems/minimum-number-of-vertices-to-reach-all-nodes/
*/
class Solution {
public:
        vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> A(n,true);       
        for(auto e:edges){
            A[e[1]]=false;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(A[i])
                ans.push_back(i);
        }
        return ans;
            }
};
