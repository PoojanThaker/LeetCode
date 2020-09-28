/*
Author : Poojan Thaker 
Problem name : Teemo Attacking
Runtime : 68 ms 
Memory : 26.2 MB
Problem link : https://leetcode.com/problems/teemo-attacking/
*/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total=0;
        if(timeSeries.size()==0)return 0;
                for(int i=1;i<timeSeries.size();i++){
            total+=min((timeSeries[i]-timeSeries[i-1]),duration);
        }
                return total+duration;
    }
};
