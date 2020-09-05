/*
Author : Poojan Thaker 
Problem name : Number of Ways to Split a String
Runtime : 176 ms 
Memory : 15.7 MB
Problem link : https://leetcode.com/contest/biweekly-contest-34/problems/number-of-ways-to-split-a-string/
*/
class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int numWays(string s) {
        int oc = 0;
        for(auto x:s)
            if(x=='1')
                oc++;
                if(oc%3!=0)return 0;
                oc/=3;
                int cc=0;
        vector<ll> ii;
                for(int i=0;i<s.length();i++){
            if(s[i]=='1')
             ii.push_back(i);        
        }
                if(ii.empty()){
            ll n = s.length();
            return (((n-1)*(n-2))/2)%mod;
        }
        return ((((ii[oc]%mod-ii[oc-1]%mod+mod))%mod)*(((ii[2*oc]%mod-ii[2*oc-1]%mod+mod))%mod))%mod;
    }
};
