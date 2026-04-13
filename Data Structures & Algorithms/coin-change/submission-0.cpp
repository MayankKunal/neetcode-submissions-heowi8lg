class Solution {
      long long help(int i,int n,vector<int>&coins,int amount)
      {
        if(i==n)
        {
            if(amount==0)
            {
            return 0;
            }
            return INT_MAX;
        }
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        return min(1+help(i,n,coins,amount-coins[i]),help(i+1,n,coins,amount));
      }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        long long ans=help(0,n,coins,amount);
        if(ans>=INT_MAX) return -1;
        return ans;
    }
};
