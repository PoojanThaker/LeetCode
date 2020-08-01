/*
Author : Poojan Thaker 
Problem name : Detect Capital
Runtime : 4 ms 
Memory : 6.2 MB
Problem link : https://leetcode.com/problems/detect-capital/
*/
class Solution {
public:
    bool isCap(char c){
        return c<='Z'&&c>='A';
    }
        bool allSmall(string& s,int si){
        for(int i=si;i<s.length();i++){
            if(isCap(s[i]))
                return false;
        }
        return true;
    }
         bool allCaps(string& s,int si){
       for(int i=si;i<s.length();i++){
            if(!isCap(s[i]))
                return false;
        }
        return true;
    }
        bool detectCapitalUse(string word) {
        return ((!isCap(word[0]))&&(allSmall(word,1)))||(isCap(word[0])&&(allCaps(word,1)||allSmall(word,1)))   
             ; 
    }
