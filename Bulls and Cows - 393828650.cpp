/*
Author : Poojan Thaker 
Problem name : Bulls and Cows
Runtime : 24 ms 
Memory : 9.3 MB
Problem link : https://leetcode.com/problems/bulls-and-cows/
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_multiset<char> potential_crows;
        string bulls_removed_guess;
        int bulls=0;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                potential_crows.insert(secret[i]);
                bulls_removed_guess.push_back(guess[i]);
            }
        }
        int crows=0;
        for(auto x:bulls_removed_guess){
            if(potential_crows.find(x)!=potential_crows.end()){
                potential_crows.erase(potential_crows.find(x));
                crows++;
            }
        }
                return to_string(bulls)+"A"+to_string(crows)+"B";
    }
};
