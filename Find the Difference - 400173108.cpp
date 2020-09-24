/*
Author : Poojan Thaker 
Problem name : Find the Difference
Runtime : 8 ms 
Memory : 6.9 MB
Problem link : https://leetcode.com/problems/find-the-difference/
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> ff;
        for(auto x:t)ff[x]++;
        for(auto x:s){
            ff[x]--;
        }
        for(auto x:ff){
            if(x.second!=0)
                return x.first;
        }
        return 'c';
    }
};
