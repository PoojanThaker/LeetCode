/*
Author : Poojan Thaker 
Problem name : Find Common Characters
Runtime : 44 ms 
Memory : 14.5 MB
Problem link : https://leetcode.com/problems/find-common-characters/
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        unordered_map<char,int> freq[n];
                for(int i=0;i<A.size();i++){
            for(auto x:A[i]){
                freq[i][x]++;
            }
        }
                vector<string> ans;
                for(char x='a';x<='z';x++){
            int minfreq=INT_MAX;
            for(int i=0;i<n;i++){
                minfreq=min(minfreq,freq[i][x]);
            }
                        while(minfreq--)
                ans.push_back(string(1,x));
                    }
                return ans;
    }
};
