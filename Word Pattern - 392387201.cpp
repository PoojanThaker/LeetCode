/*
Author : Poojan Thaker 
Problem name : Word Pattern
Runtime : 0 ms 
Memory : 6.5 MB
Problem link : https://leetcode.com/problems/word-pattern/
*/
class Solution {
public:
        vector<string> split_to_words(string str){
        stringstream ss(str);
        vector<string> ans;
        while(1){
            string word;
            ss>>word;
            if(word.empty())break;
                        ans.push_back(word);
        }
        return ans;
    }
            bool wordPattern(string pattern, string str) {
        vector<string> words = split_to_words(str);
                if(pattern.length()!=words.size())return false;
                unordered_map<string,char> fmap;
        unordered_map<char,string> rmap;
                for(int i=0;i<words.size();i++){
            if(fmap.count(words[i])&&fmap[words[i]]!=pattern[i])
                return false;
            fmap[words[i]]=pattern[i];
                   }
                  for(int i=0;i<words.size();i++){
            if(rmap.count(pattern[i])&&rmap[pattern[i]]!=words[i])
                return false;
            rmap[pattern[i]]=words[i];
                   }
                                    return true;
            }
};
