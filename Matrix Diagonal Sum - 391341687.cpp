/*
Author : Poojan Thaker 
Problem name : Matrix Diagonal Sum
Runtime : 68 ms 
Memory : 11.5 MB
Problem link : https://leetcode.com/contest/biweekly-contest-34/problems/matrix-diagonal-sum/
*/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
                int ans=0;
                for(int i=0;i<n;i++){
            ans+=mat[i][i];
            ans+=mat[i][n-i-1];
        }
        if(n%2)
        ans-=mat[n/2][n/2];
                return ans;
    }
};
