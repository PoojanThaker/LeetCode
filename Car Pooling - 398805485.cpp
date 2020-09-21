/*
Author : Poojan Thaker 
Problem name : Car Pooling
Runtime : 24 ms 
Memory : 10 MB
Problem link : https://leetcode.com/problems/car-pooling/
*/
 class Solution {
public:
                bool carPooling(vector<vector<int>>& trips, int capacity) {
                vector<pair<int,int>> locs;
        for(auto x:trips){
            locs.push_back({x[1],x[0]});
            locs.push_back({x[2],-1*x[0]});
        }
                sort(locs.begin(),locs.end());
                int cc=0;
        int maxc=0;
        for(auto x:locs){
            cc+=x.second;
            maxc=max(maxc,cc);
        }
                return maxc<=capacity;
            }
};
