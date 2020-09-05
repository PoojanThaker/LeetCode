/*
Author : Poojan Thaker 
Problem name : Count All Possible Routes
Runtime : 136 ms 
Memory : 8.8 MB
Problem link : https://leetcode.com/contest/biweekly-contest-34/problems/count-all-possible-routes/
*/
class Solution {
public:
    #define mod 1000000007
    int memo[100][201];
        int dp(int current,int end,int fuel_rem,vector<int>& locations){
                if(fuel_rem==0){
            if(current==end){
                return 1;
            }
            else{
                return 0;
            }
        }
            if(memo[current][fuel_rem]!=-1) return memo[current][fuel_rem];
        int ans=0;    
        for(int i=0;i<locations.size();i++){
            if(i!=current){
                int diff=abs(locations[i]-locations[current]);
                if(diff<=fuel_rem){
                    ans=(ans+dp(i,end,fuel_rem-diff,locations))%mod;
                }
            }
        }
        if(current==end){
            ans++;
            ans%=mod;
        }   
        memo[current][fuel_rem]=ans;
        return ans;
    }
                int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        for(int i=0;i<locations.size();i++){
            for(int j=0;j<=fuel;j++)
                memo[i][j]=-1;
        }
                return dp(start,finish,fuel,locations);
    }
};
