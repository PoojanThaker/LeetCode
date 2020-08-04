/*
Author : Poojan Thaker 
Problem name : Path Crossing
Runtime : 8 ms 
Memory : 6.7 MB
Problem link : https://leetcode.com/problems/path-crossing/
*/
class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visited;
        int currentX=0;
        int currentY=0;
          visited.insert({currentX,currentY});
        for(auto x:path){
            switch(x){
                case'N':{
                    currentY++;
                    break;
                }
                case'S':{
                    currentY--;
                    break;
                }
                case'E':{
                    currentX++;
                    break;
                }
                case'W':{
                    currentX--;
                }
            }
                        if(visited.count({currentX,currentY}))
                return true;  
                 visited.insert({currentX,currentY});
        }
                return false;
    }
};
