/*
Author : Poojan Thaker 
Problem name : Power of Two
Runtime : 0 ms 
Memory : 6.1 MB
Problem link : https://leetcode.com/problems/power-of-two/
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return 0;
        if(n==INT_MIN)return 0;
        return (n&(n-1))==0;
    }
};
