class Solution {
    int help(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int take=nums[i]+help(i+2,n,nums,dp);
        int notTake=help(i+1,n,nums,dp);
        return dp[i]=max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+1,-1);
        vector<int>dp2(n+1,-1);

        return max(help(0,n-1,nums,dp),
        help(1,n,nums,dp2));
    }
};
