/*
Author : Poojan Thaker 
Problem name : Repeated Substring Pattern
Runtime : 80 ms 
Memory : 24.7 MB
Problem link : https://leetcode.com/problems/repeated-substring-pattern/
*/
class Solution {
public:
    vector<int> prefix_function(string &s) 
    {
        int n = s.size();
        vector<int> pi(n);
        for(int i = 1; i < n; i++) 
        {
            int j = pi[i - 1];
            while(j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    vector<int> find_occurences(string &text, string &pattern)
    {
        string cur = pattern + '#' + text;
        int sz1 = text.size(), sz2 = pattern.size();
        vector<int> v;
        vector<int> lps = prefix_function(cur);
        for(int i = sz2 + 1; i <= sz1 + sz2; i++)
        {
            if(lps[i] == sz2)
                v.push_back(i - 2 * sz2);
        }
        return v;
    }
        bool repeatedSubstringPattern(string s) {
        string s2 = s+s;
        s2.pop_back();
        s2.erase(s2.begin());
                return !find_occurences(s2,s).empty();
    }
};
