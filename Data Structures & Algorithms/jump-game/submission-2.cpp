class Solution {
    
    int help(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        
        if(i>=n-1)
        {
            return true; 
        }
        if(dp[i]!=-1) return dp[i];
         // if(i<n-1  && nums[i]==0) return false;
        bool ans=false;
        for(int idx=1;idx<=nums[i];idx++)
        {
            ans=ans||help(i+idx,n,nums,dp);
        }
       return dp[i]=ans;
    }
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return help(0,n,nums,dp);
    }
};
