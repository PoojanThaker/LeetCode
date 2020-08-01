/*
Author : Poojan Thaker 
Problem name : Number of Substrings Containing All Three Characters
Runtime : 160 ms 
Memory : 14.2 MB
Problem link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int j=0;
        unordered_map<char,int> m1;
        int ans=0;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
            while(m1.size()==3&&j<i){
                m1[s[j]]--;
                if(m1[s[j]]==0)m1.erase(s[j]);
                j++;
            }
            ans+=j;
        }
        return ans;
    }
};
