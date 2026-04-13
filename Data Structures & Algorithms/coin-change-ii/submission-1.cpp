class Solution {
    int help(int i,int n,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(i>=n)
        {
            if(amount==0) return 1;
            return 0;
        }
       if(amount==0) return 1;
       if(amount<0) return 0;
       if(dp[i][amount]!=-1) return dp[i][amount];
       return dp[i][amount]=help(i,n,amount-coins[i],coins,dp)+help(i+1,n,amount,coins,dp);
    }
public:
    int change(int amount, vector<int>& coins) {
        
    
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return help(0,n,amount,coins,dp);
    }
};
