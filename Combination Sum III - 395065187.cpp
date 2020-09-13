/*
Author : Poojan Thaker 
Problem name : Combination Sum III
Runtime : 4 ms 
Memory : 13.5 MB
Problem link : https://leetcode.com/problems/combination-sum-iii/
*/
class Solution {
public:
        vector<vector<int>> fin_res;
        void find_combinations(int current_num,int k,int sum_rem,vector<int> current_combination){
                //base case
        if(current_combination.size()==k){
            if(sum_rem==0){
                fin_res.push_back(current_combination);
            }
            return;
        }
                if(current_num>9){
            return;
        }
                        find_combinations(current_num+1,k,sum_rem,current_combination);
                if(sum_rem-current_num>=0){
            current_combination.push_back(current_num);
            find_combinations(current_num+1,k,sum_rem-current_num,current_combination);
        }
            }
                vector<vector<int>> combinationSum3(int k, int n) {
        fin_res.clear();
        vector<int> current_combination;
        find_combinations(1,k,n,current_combination);
        return fin_res;
    }
};
