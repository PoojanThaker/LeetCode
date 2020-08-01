/*
Author : Poojan Thaker 
Problem name : Search in Rotated Sorted Array
Runtime : 12 ms 
Memory : 11.3 MB
Problem link : https://leetcode.com/problems/search-in-rotated-sorted-array/
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        int rot;
        while(1){
            int mid = (hi+lo)/2;
            if(lo>hi){
                rot=lo;
                break;
            }
            if(nums[mid]>nums.back()){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        int n = nums.size();
        int ans;
        lo=0;
        hi=n-1;
        while(1){
            int mid = (hi+lo)/2;
            if(lo>hi)return -1;
            if(nums[(mid+rot)%n]==target)return (mid+rot)%n;
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
