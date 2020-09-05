/*
Author : Poojan Thaker 
Problem name : Shortest Subarray to be Removed to Make Array Sorted
Runtime : 384 ms 
Memory : 70.2 MB
Problem link : https://leetcode.com/contest/biweekly-contest-34/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
*/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
                if(arr.size()==1)return 0;
                vector<int> p2={arr.back()};
                for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]<=arr[i+1]){
                p2.push_back(arr[i]);
            }
            else{
                break;
            }
        }
        reverse(p2.begin(),p2.end());
        vector<int> p1 = {arr[0]};
                for(int i=1;i<arr.size();i++){
            if(arr[i]>=arr[i-1]){
                p1.push_back(arr[i]);
            }
            else{
                break;
            }
        }
                if(p2.size()==arr.size())return 0;
                int minposs = arr.size();
        int n = arr.size();
        //         for(auto x:p1)cout<<x<<" ";
//         cout<<endl;
        //         for(auto x:p2)cout<<x<<" ";
//         cout<<endl;
                for(int i=0;i<p1.size();i++){
            auto ix = lower_bound(p2.begin(),p2.end(),p1[i]);
            int ele = p2.end()-ix;
            minposs=min(minposs,n-(ele+i+1));
        }
                minposs=min(minposs,n-(int)p2.size());
        minposs=min(minposs,n-(int)p1.size());
                return minposs;
    }
};
