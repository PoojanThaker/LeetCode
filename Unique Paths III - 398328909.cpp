/*
Author : Poojan Thaker 
Problem name : Unique Paths III
Runtime : 80 ms 
Memory : 17.6 MB
Problem link : https://leetcode.com/problems/unique-paths-iii/
*/
class Solution {
public:
    int ans=0;
        void findPaths(int x,int y,vector<vector<int>>& grid,vector<vector<bool>> visited){
                visited[x][y]=true;
                if(grid[x][y]==2){
            bool alldone=true;
            for(int i=0;i<grid.size();i++)
                for(int j=0;j<grid[0].size();j++)
                 if(visited[i][j]==false&&grid[i][j]!=-1)
                     alldone=false;
            if(alldone)
            ans++;
            return;
        }
                             vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};
                for(int dir=0;dir<4;dir++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];
                        if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&visited[nx][ny]==false&&grid[nx][ny]!=-1){
                findPaths(nx,ny,grid,visited);
            }
                    }
            }
            int uniquePathsIII(vector<vector<int>>& grid) {
        ans=0;
        int n = grid.size();
        int m =grid[0].size();
        int sx;
        int sy;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        findPaths(sx,sy,grid,visited);
        return ans;
    }
};
