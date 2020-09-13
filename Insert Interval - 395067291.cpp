/*
Author : Poojan Thaker 
Problem name : Insert Interval
Runtime : 88 ms 
Memory : 17.9 MB
Problem link : https://leetcode.com/problems/insert-interval/
*/
class Solution {
public:
        vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& intervals){
        vector<vector<int>> finAns;
                for(auto i:intervals){
            if(finAns.empty()||finAns.back()[1]<i[0]){
                finAns.push_back(i);
            }
            else{
                if(i[1]>finAns.back()[1]){
                    vector<int> lastInterval = finAns.back();
                    finAns.pop_back();
                    lastInterval[1]=i[1];
                    finAns.push_back(lastInterval);
                }
            }
        }
                return finAns;
    }
                        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        return mergeOverlappingIntervals(intervals);
    }
};
