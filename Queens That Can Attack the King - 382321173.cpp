/*
Author : Poojan Thaker 
Problem name : Queens That Can Attack the King
Runtime : 12 ms 
Memory : 11.3 MB
Problem link : https://leetcode.com/problems/queens-that-can-attack-the-king/
*/
class Solution {
public:
        bool isValid(int x,int y){
        return x>=0&&y>=0&&x<8&&y<8;
    }
            vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
                vector<vector<bool>> is_queen(8,vector<bool>(8,false));
        for(auto queen:queens){
            is_queen[queen[0]][queen[1]]=true;
        }
                for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0&&j==0)continue;     
                int curr_x = king[0];
                int curr_y = king[1];
                while(isValid(curr_x,curr_y)){
                    if(is_queen[curr_x][curr_y]){
                        ans.push_back({curr_x,curr_y});
                        break;
                    }
                    curr_x+=i;
                    curr_y+=j;
                }
            }
        }
                return ans;
            }
};
