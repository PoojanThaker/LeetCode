/*
Author : Poojan Thaker 
Problem name : Largest Number
Runtime : 8 ms 
Memory : 11.7 MB
Problem link : https://leetcode.com/problems/largest-number/
*/
    bool cmp(string A,string B){
        if(A+B>B+A){
            return true;
        }
        return false;
    }
        string removez(string t){
        string ans;
        int i=0;
        while(i<t.length()&&t[i]=='0')
            i++;
        if(i==t.length())return "0";
        while(i<t.length())
            ans.push_back(t[i++]);
        return ans;
            }
class Solution {
public:
            string largestNumber(vector<int>& nums) {
        vector<string> all_nums;
        for(auto x:nums)
            all_nums.push_back(to_string(x));
        sort(all_nums.begin(),all_nums.end(),cmp);
                string ans;
        for(auto x:all_nums)ans+=x;
        return removez(ans);
            }
};
