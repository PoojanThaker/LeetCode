/*
Author : Poojan Thaker 
Problem name : Perfect Number
Runtime : 0 ms 
Memory : 6 MB
Problem link : https://leetcode.com/problems/perfect-number/
*/
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1||num==0)return false;
        int sum_of_divisors=0;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                sum_of_divisors+=i;
                if(i*i!=num&&i!=1){
                    sum_of_divisors+=num/i;
                }
            }
        }
        return sum_of_divisors==num;
    }
};
