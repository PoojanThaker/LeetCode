/*
Author : Poojan Thaker 
Problem name : Can Make Palindrome from Substring
Runtime : 904 ms 
Memory : 152.6 MB
Problem link : https://leetcode.com/problems/can-make-palindrome-from-substring/
*/
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = s.length();
        vector<vector<int>> freq(n+1,vector<int>(26,0));
                for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++){
                freq[i][j]=freq[i-1][j];
            }
            freq[i][s[i-1]-'a']++;
        }
               for(auto query:queries){
            int l = query[0];          
            int r = query[1];
            int k = query[2];
            int odd_count=0;
            for(int i=0;i<26;i++){
                odd_count+=(freq[r+1][i]-freq[l][i])%2;
            }
            ans.push_back((odd_count/2)<=k);
        }
                return ans;
    }
};
