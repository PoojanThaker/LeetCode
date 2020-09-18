/*
Author : Poojan Thaker 
Problem name : Robot Bounded In Circle
Runtime : 0 ms 
Memory : 6.3 MB
Problem link : https://leetcode.com/problems/robot-bounded-in-circle/
*/
class Solution {
public:
    bool isRobotBounded(string in) {
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int n = in.size();
        int cx=0;
        int cy=0;
        int di=0;
        for(int i=0;i<4*n;i++){
            if(in[i%n]=='L'){
                di--;
                di+=4;
                di%=4;
            }
            else if(in[i%n]=='R'){
                di++;
                di+=4;
                di%=4;
            }
            else{
                cx+=dir[di].first;
                cy+=dir[di].second;
            }
                    }
                return cx==0&cy==0;
                    }
};
