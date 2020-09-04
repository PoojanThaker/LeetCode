/*
Author : Poojan Thaker 
Problem name : Partition Labels
Runtime : 12 ms 
Memory : 7 MB
Problem link : https://leetcode.com/problems/partition-labels/
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<int,int> last_index;
        for(int i=0;i<S.length();i++){
            last_index[S[i]]=i;
        }
                vector<int> starts={0};
        int current_reach=0;
                for(int i=0;i<S.length();i++){
            if(i>current_reach){
                starts.push_back(i);
                current_reach=i;
            }
            current_reach=max(current_reach,last_index[S[i]]);
        }
                vector<int> ans;
                for(int i=1;i<starts.size();i++){
            ans.push_back(starts[i]-starts[i-1]);
        }
                ans.push_back(S.size()-starts.back());
                return ans;
    }
};
