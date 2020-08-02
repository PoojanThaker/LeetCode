/*
Author : Poojan Thaker 
Problem name : Complement of Base 10 Integer
Runtime : 0 ms 
Memory : 5.9 MB
Problem link : https://leetcode.com/problems/complement-of-base-10-integer/
*/
class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)return 1;
        int mul=1;
        int ans=0;
        while(N){
            if(!(N&1))
            ans+=mul;
            mul<<=1;
            N>>=1;
        }
        return ans;
    }
};
