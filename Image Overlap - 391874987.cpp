/*
Author : Poojan Thaker 
Problem name : Image Overlap
Runtime : 736 ms 
Memory : 208 MB
Problem link : https://leetcode.com/problems/image-overlap/
*/
class Solution {
public:
        int findint(vector<vector<int>>& A,vector<vector<int>>& B){
        int ans=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                ans+=(A[i][j]&B[i][j]);
            }
        }
        return ans;
    }
                int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
                vector<int> dx;
        vector<int> dy;
        for(int i=-(n-1);i<=(n-1);i++){
            dx.push_back(i);
            dy.push_back(i);
        }
        int finans=0;
        for(auto x:dx){
            for(auto y:dy){
                vector<vector<int>> disp(n,vector<int>(n));               
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int nx = i+x;
                        int ny = j+y;
                        int ans=0;
                        if(nx<n&&nx>=0&&ny<n&&ny>=0)
                            ans=A[nx][ny];
                        // cout<<nx<<" "<<ny<<" "<<ans<<endl;
                        disp[i][j]=ans;
                    }
                }
                //  for(int i=0;i<n;i++){
                //     for(int j=0;j<n;j++){
                //         cout<<disp[i][j]<<" ";
                //     }
                //      cout<<endl;
                // }
                // cout<<endl;
                finans=max(finans,findint(disp,B));
                            }
        }
        return finans;
            }
};
