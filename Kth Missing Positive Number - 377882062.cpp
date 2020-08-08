/*
Author : Poojan Thaker 
Problem name : Kth Missing Positive Number
Runtime : 16 ms 
Memory : 12.9 MB
Problem link : https://leetcode.com/contest/biweekly-contest-32/problems/kth-missing-positive-number/
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int j=0;
        for(int i=1;i<=3000;i++){
            if(j<arr.size()&&arr[j]==i){
                j++;
            }
            else{
                missing.push_back(i);
            }
        }
        return missing[k-1];
    }
};
