/*
Author : Poojan Thaker 
Problem name : Sequential Digits
Runtime : 4 ms 
Memory : 7 MB
Problem link : https://leetcode.com/problems/sequential-digits/
*/
class Solution {
public:
    #define ll long long
    vector<ll> convert(set<string> s){
        vector<ll> ans;
        for(auto x:s){
            ans.push_back(stoll(x));
        }
        return ans;
    }
          vector<ll> generate(int x){
                set<string> s;
                for(char start='1';start<='9';start++){
            char cc=start;
            string curr;
            int j=x;
             while(j--&&cc<='9'){
                 curr.push_back(cc);
                 cc++;
             }
             s.insert(curr);
        }
                              return convert(s);
    }
                vector<int> sequentialDigits(int low, int high) {
        set<ll> all_nums;
                for(int dig=2;dig<10;dig++){
            vector<ll> pp = generate(dig);
            for(auto x:pp)
                all_nums.insert(x);
        }
                vector<int> ans;
        for(auto x:all_nums){
            if(x>=low&&x<=high)
                ans.push_back(x);
        }
        return ans;
    }
};
