/*
Author : Poojan Thaker 
Problem name : Maximum XOR of Two Numbers in an Array
Runtime : 196 ms 
Memory : 38.1 MB
Problem link : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/
class node{
    public:
  char val;
  node*left;
  node*right;           
};
 node* newnode(char v){
      node*x = new node();
      x->val=v;
      x->right=NULL;
      x->left=NULL;
      return x;
  }
class Trie{
   public:
   node*head;
        Trie(){
        this->head = newnode('h');
    }
       void add_num(string s){
       node*curr = this->head;
       for(int i=0;i<s.length();i++){
           if(s[i]=='0'){
               if(curr->left==NULL)
                   curr->left=newnode('0');
               curr=curr->left;
           }
           else{
               if(curr->right==NULL)
                   curr->right=newnode('1');
               curr=curr->right;
           }
       }
   }
        int findxor(string s){
        node*curr = this->head;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                if(curr->left){
                    curr=curr->left;
                    ans+=(1<<(31-i));
                }
                else{
                    curr=curr->right;
                }
            }
            else{
                  if(curr->right){
                    curr=curr->right;
                    ans+=(1<<(31-i));
                }
                else{
                    curr=curr->left;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
            string numToString(int num){
        string ans;
        for(int i=31;i>=0;i--){
            if((num&(1<<i))!=0){
                ans.push_back('1');
            }
            else{
                ans.push_back('0');
            }
        }
        return ans;
    }
            int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto x:nums){
            t.add_num(numToString(x));
        }
                int ans = INT_MIN;
                for(auto x:nums){
            ans=max(ans,t.findxor(numToString(x)));
        }
                return ans;
    }
};
