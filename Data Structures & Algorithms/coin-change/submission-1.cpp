class Solution {
      long long help(int i,int n,vector<int>&coins,int amount,vector<vector<long long>>&dp)
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
        if(dp[i][amount]!=-1) return dp[i][amount];
        return dp[i][amount]=min(1+help(i,n,coins,amount-coins[i],dp),help(i+1,n,coins,amount,dp));
      }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<long long>>dp(n+1,vector<long long>(amount+1,-1));
        long long ans=help(0,n,coins,amount,dp);
        if(ans>=INT_MAX) return -1;
        return ans;
    }
};
