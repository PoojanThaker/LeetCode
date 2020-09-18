/*
Author : Poojan Thaker 
Problem name : Making A Large Island
Runtime : 44 ms 
Memory : 15.8 MB
Problem link : https://leetcode.com/problems/making-a-large-island/
*/
class Solution {
public:
        int DFS(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& color,int cc){
             vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        int ans=1;
        color[x][y]=cc;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
                        if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&color[nx][ny]==-1&&grid[nx][ny]==1){
                ans+=DFS(nx,ny,grid,color,cc);
            }
                    }
        return ans;
    }
                int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
                vector<vector<int>> color(n,vector<int>(m,-1));
        int cc=0;
        vector<int> color_to_size;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(color[i][j]==-1&&grid[i][j]==1){
                    color_to_size.push_back(DFS(i,j,grid,color,cc++));
                }
            }
        }
                int finans=0;
        if(!color_to_size.empty())
        finans = *max_element(color_to_size.begin(),color_to_size.end());
                 for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(color[i][j]==-1){
                     vector<int> dx = {1,-1,0,0};
                     vector<int> dy = {0,0,1,-1};
                     int ans=0;
                     set<int> comps;
                      for(int ii=0;ii<4;ii++){
                        int nx = i+dx[ii];
                        int ny = j+dy[ii];
                        if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&color[nx][ny]!=-1){
                            comps.insert(color[nx][ny]);
                        }
                    }
                                        for(auto x:comps){
                        ans+=color_to_size[x];
                    }
                                        finans=max(finans,ans+1);
                }
            }
        }
                return finans;
            }
};
