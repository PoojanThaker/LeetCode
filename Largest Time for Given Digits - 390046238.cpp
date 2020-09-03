/*
Author : Poojan Thaker 
Problem name : Largest Time for Given Digits
Runtime : 4 ms 
Memory : 10 MB
Problem link : https://leetcode.com/problems/largest-time-for-given-digits/
*/
class Solution {
public:
        bool isValid(string s){
        string hours = s.substr(0,2);
        string minutes = s.substr(3,2);
                return hours<="23"&&minutes<="59";
    }
            string largestTimeFromDigits(vector<int>& A) {
                vector<string> valid_times;
        sort(A.begin(),A.end());
        while(1){
                        string time;
            for(int i=0;i<A.size();i++){
                if(i==2){
                    time.push_back(':');
                }
                time.push_back(A[i]+'0');
            } 
                                 if(isValid(time)){
                    valid_times.push_back(time);
                }
            bool has_next = next_permutation(A.begin(),A.end());
            if(!has_next)break;
        }
        sort(valid_times.begin(),valid_times.end());
        if(valid_times.empty())return "";
         return valid_times.back();
    }
};
