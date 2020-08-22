/*
Author : Poojan Thaker 
Problem name : Minimum Numbers of Function Calls to Make Target Array
Runtime : 220 ms 
Memory : 25.7 MB
Problem link : https://leetcode.com/contest/biweekly-contest-33/problems/minimum-numbers-of-function-calls-to-make-target-array/
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxb=0;
        int nbit=0;
        for(auto x:nums){
            int ob=0;
            int tb=0;
            while(x){
                tb++;
                if(x&1)
                ob++;
                x>>=1;
            }
            maxb=max(maxb,tb);
            nbit+=ob;
        }
                return maxb-1+nbit;
    }
};
