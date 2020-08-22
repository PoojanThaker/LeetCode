/*
Author : Poojan Thaker 
Problem name : Thousand Separator
Runtime : 0 ms 
Memory : 6.1 MB
Problem link : https://leetcode.com/contest/biweekly-contest-33/problems/thousand-separator/
*/
class Solution {
public:
    string thousandSeparator(int n) {
        if(n==0)return string(1,'0');
        string ans;
        while(n){
            char d = n%10+'0';
            n/=10;
            ans.push_back(d);
        }
        string fans;
        for(int i=0;i<ans.length();i++){
            fans.push_back(ans[i]);
            if((i+1)%3==0)
                fans.push_back('.');
        }
        if(fans.back()=='.')fans.pop_back();
        reverse(fans.begin(),fans.end());
        cout<<fans<<endl;
        return fans;
    }
};
