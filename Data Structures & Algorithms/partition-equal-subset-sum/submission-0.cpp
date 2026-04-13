class Solution {
    bool help(int i,int n,int sum,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            if(sum==0) return 1;
            else
            return 0;
        }
        if(sum==0) return 1;
        if(sum<0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take=help(i+1,n,sum-nums[i],nums,dp);
        int notTake=help(i+1,n,sum,nums,dp);
        return dp[i][sum]=take||notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int x:nums)
        {
            sum+=x;
        }
        if(sum%2!=0) return 0;
        sum/=2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return help(0,n,sum,nums,dp);
    }
};
