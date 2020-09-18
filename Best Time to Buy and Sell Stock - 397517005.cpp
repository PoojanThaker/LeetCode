/*
Author : Poojan Thaker 
Problem name : Best Time to Buy and Sell Stock
Runtime : 12 ms 
Memory : 13.2 MB
Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2)return 0;
        int maxr[n];
        maxr[n-1]=INT_MIN;
        for(int i=n-2;i>=0;i--){
            maxr[i]=max(maxr[i+1],prices[i+1]);
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,maxr[i]-prices[i]);
        }
        return ans;
    }
};
