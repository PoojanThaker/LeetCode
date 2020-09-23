/*
Author : Poojan Thaker 
Problem name : Gas Station
Runtime : 12 ms 
Memory : 10 MB
Problem link : https://leetcode.com/problems/gas-station/
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int n = gas.size();
        for(int i=0;i<n;i++){
            int start=i;
            int cc=0;
            bool poss=true;
            for(int j=start;j<start+n;j++){
                cc+=gas[j%n];
                cc-=cost[j%n];
                if(cc<0){
                    poss=false;
                    i=j;
                    break;
                }
            }
            if(poss){
                return start;
            }
        }
        return -1;
    }
};
