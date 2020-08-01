/*
Author : Poojan Thaker 
Problem name : https://leetcode.com/problems/median-of-two-sorted-arrays/
Runtime : 56 ms 
Memory : 89.3 MB
Problem link : https://leetcode.com/problems/median-of-two-sorted-arrays/
*/
int getVal(vector<int>& v,int ind){
      if(ind<0)return INT_MIN;
    if(ind>=v.size())return INT_MAX;
    return v[ind];
}
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int leftele = (n+m)/2;
        int lo=max(0,leftele-m);
        int hi=min(n,(n+m)/2);
        int ans;
        while(1){            
            int mid=(hi+lo)/2;
            int other = leftele-mid;           
            if(getVal(nums1,mid-1)<=getVal(nums2,other)&&getVal(nums1,mid)>=getVal(nums2,other-1)){
                ans=mid;
                break;
            }
            else if(getVal(nums1,mid-1)>getVal(nums2,other)){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
                if((n+m)%2==1){
            return min(getVal(nums1,ans),getVal(nums2,leftele-ans));
        }
        else{
            return ((double)min(getVal(nums1,ans),getVal(nums2,leftele-ans))+
                    (double)max(getVal(nums1,ans-1),getVal(nums2,leftele-ans-1)))/2;
        }
        return 0;
    }
};
