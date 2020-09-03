/*
Author : Poojan Thaker 
Problem name : Contains Duplicate III
Runtime : 36 ms 
Memory : 11.6 MB
Problem link : https://leetcode.com/problems/contains-duplicate-iii/
*/
class Solution {
public:
    #define ll long long
    bool containsNearbyAlmostDuplicate(vector<int>& n, int k1, int t1) {
                     vector<ll> nums;
        for(auto x:n)nums.push_back(x);
           if(nums.empty())return false;
        ll k=k1;
        ll t=t1;
        if(k==0)return false;
        multiset<ll> all_nums;
        for(int i=0;i<k;i++){
            if(i<nums.size())
            all_nums.insert(nums[i]);
        }
                for(int i=0;i<nums.size()-1;i++){
            all_nums.erase(all_nums.find(nums[i]));
                                               if(i+k<nums.size())
            all_nums.insert(nums[i+k]);
                        auto ip = all_nums.lower_bound(nums[i]);
                         if(ip==all_nums.end()){
                 auto prev = --ip;
                                  if(nums[i]-*prev<=t){
                     return true;
                 }
                              }
                 else{
                                          if(*ip-nums[i]<=t)return true;
                                                                                      if(ip!=all_nums.begin()){
                    auto prev = --ip;
                    ++ip;
                    if(nums[i]-*prev<=t)return true;
                }
                auto next = ++ip;
                --ip;
                if(next!=all_nums.end()){
                    if(*next-nums[i]<=t)
                        return true;
                }
             }
                     }
        return false;
    }
};
