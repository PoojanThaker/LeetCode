/*
Author : Poojan Thaker 
Problem name : House Robber
Runtime : 4 ms 
Memory : 7.7 MB
Problem link : https://leetcode.com/problems/house-robber/
*/
class Solution {
public:
        int memo[101];
        int dp(int i,vector<int>&nums){
                if(i>=nums.size())return 0;
        if(memo[i]!=-1)return memo[i];
        int ans = max(nums[i]+dp(i+2,nums),dp(i+1,nums));
                memo[i]=ans;
        return ans;
    }
                int rob(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)memo[i]=-1;
        return dp(0,nums);
    }
};
