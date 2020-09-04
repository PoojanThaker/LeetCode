/*
Author : Poojan Thaker 
Problem name : Guess Number Higher or Lower
Runtime : 0 ms 
Memory : 6.2 MB
Problem link : https://leetcode.com/problems/guess-number-higher-or-lower/
*/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is lower than the guess number
 *                1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n) {
                int lo = 1;
        int hi = n;
                while(1){
            int mid = lo+(hi-lo)/2;
                        int poss = guess(mid);
                        if(poss==0)return mid;
            else if(poss==1){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
            }
};
