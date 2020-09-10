/*
Author : Poojan Thaker 
Problem name : Compare Version Numbers
Runtime : 4 ms 
Memory : 6.4 MB
Problem link : https://leetcode.com/problems/compare-version-numbers/
*/
class Solution {
public:
        int num_to_string(string s){
        int num=0;
        for(auto x:s){
            num*=10;
            num+=x-'0';
        }
        return num;
    }
            vector<int> separate(string s){
        vector<string> chunks;
        string current;
                for(int i=0;i<s.length();i++){
            if(s[i]=='.'){
                chunks.push_back(current);
                current="";
            }
            else{
                current.push_back(s[i]);
            }
        }
        chunks.push_back(current);
                vector<int> ans;
        for(auto x:chunks){
            ans.push_back(num_to_string(x));
        }
                return ans;
    }
                int compareVersion(string version1, string version2) {
          vector<int> s1 = separate(version1);
          vector<int> s2 = separate(version2);
                  while(s2.size()<s1.size()){
              s2.push_back(0);
          }
                  while(s1.size()<s2.size()){
              s1.push_back(0);
          }
                  if(s1<s2)return -1;
          else if(s1>s2)return 1;
         return 0;
    }
};
