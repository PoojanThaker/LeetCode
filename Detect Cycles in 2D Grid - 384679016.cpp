/*
Author : Poojan Thaker 
Problem name : Detect Cycles in 2D Grid
Runtime : 1560 ms 
Memory : 165.1 MB
Problem link : https://leetcode.com/contest/biweekly-contest-33/problems/detect-cycles-in-2d-grid/
*/
class Solution {
public:
        bool DFS(vector<vector<char>>& grid,int x,int y,vector<vector<bool>>& visited,int px,int py){
        bool isCycle=false;
        visited[x][y]=true;
             vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int i=0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
                        if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&(grid[x][y]==grid[nx][ny])&&(!((nx==px)&&(ny==py)))){
                if(visited[nx][ny])
                    return true;
                isCycle=isCycle|DFS(grid,nx,ny,visited,x,y);
            }
        }
                return isCycle;
    }
                        bool containsCycle(vector<vector<char>>& grid) {
        bool ans=false;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j]){  
                    ans=ans|DFS(grid,i,j,visited,i,j);
                    if(ans)return true;
                }
            }
        }
        return ans;
    }
};
