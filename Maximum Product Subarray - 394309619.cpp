/*
Author : Poojan Thaker 
Problem name : Maximum Product Subarray
Runtime : 4 ms 
Memory : 12 MB
Problem link : https://leetcode.com/problems/maximum-product-subarray/
*/
class Solution {
public:
    #define ll long long
    int maxProduct(vector<int>& nums) {
        ll ans=INT_MIN;
        ll curr=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){ans=max(ans,0LL);curr=1;continue;}
            curr*=nums[i];
            ans=max(ans,curr);
        }
        curr=1;
         for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0){curr=1;continue;}
            curr*=nums[i];
            ans=max(ans,curr);
        }
                return ans;
    }
};
