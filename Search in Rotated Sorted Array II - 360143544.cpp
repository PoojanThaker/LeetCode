/*
Author : Poojan Thaker 
Problem name : Search in Rotated Sorted Array II
Runtime : 12 ms 
Memory : 13.9 MB
Problem link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())return false;
        int lo=0;
        int hi=nums.size()-1;
        while(hi>=0&&nums[lo]==nums[hi])
            hi--;
        if(hi==-1){
            return nums[0]==target;
        }
        int newend = hi;
         int rot;
        if(nums[newend]>nums[0]){
            rot=newend+1;
        }
        else
        {
            while(1){
                int mid = (hi+lo)/2;
                if(lo>hi){
                    rot=lo;
                    break;
                }
                if(nums[mid]>nums[newend]){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        int n = nums.size();
        int ans;
        lo=0;
        hi=n-1;
        while(1){
            int mid = (hi+lo)/2;
            if(lo>hi)return false;
            if(nums[(mid+rot)%n]==target)return true;
                      if(nums[(mid+rot)%n]>target){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
                return ans;
    }
};
