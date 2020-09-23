/*
Author : Poojan Thaker 
Problem name : Majority Element II
Runtime : 28 ms 
Memory : 15.8 MB
Problem link : https://leetcode.com/problems/majority-element-ii/
*/
class counter{
   public:
   int n1;
   int f1=0;
   int n2;
   int f2=0;
       void add(int n){
       // cout<<n<<" "<<n1<<" "<<f1<<" "<<n2<<" "<<f2<<endl;
       if(f1==0){
           swap(f1,f2);
           swap(n1,n2);
       }      
       if(f1==0){
           n1=n;
           f1=1;
       }
       else if(n1==n){
           f1++;
       }
       else if(f2==0){
           n2=n;
           f2=1;
       }  
       else if(n2==n){
           f2++;
       }
       else{
           f1--;
           f2--;
       }
   } 
    };
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        counter c;
        for(int i=0;i<nums.size();i++){
            c.add(nums[i]);
        }
                vector<int> ans;
        int f1=0;
        int f2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==c.n1)
                f1++;
            else if(nums[i]==c.n2)
                f2++;
        }
                int n = nums.size();
        if(f1>n/3)ans.push_back(c.n1);
        if(f2>n/3)ans.push_back(c.n2);
        // cout<<f1<<" "<<f2<<endl;
        return ans;
            }
};
