/*
Author : Poojan Thaker 
Problem name : Shift 2D Grid
Runtime : 40 ms 
Memory : 14.2 MB
Problem link : https://leetcode.com/problems/shift-2d-grid/
*/
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
                k%=m*n;
                vector<vector<int>> ans(n,vector<int>(m,0));
                int sr = k/m;
        int sc = k%m;
                for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[sr][sc]=grid[i][j];
                sc++;
                if(sc==m){
                    sc=0;
                    sr++;
                    if(sr==n)
                        sr=0;
                }
            }
        }
                return ans;
    }
};
