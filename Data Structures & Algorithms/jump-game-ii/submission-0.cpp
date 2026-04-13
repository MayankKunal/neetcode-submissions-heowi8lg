class Solution {
    long long  help(int i,int n,vector<int>&nums)
    {
        if(i>=n-1)
        {
            return 0;
        }
        long long ans=INT_MAX;
        for(int idx=1;idx<=nums[i];idx++)
        {
            ans=min(ans,1+help(i+idx,n,nums));
        }
        return ans;
    }
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
    long long ans=help(0,n,nums);
    if(ans>=INT_MAX) return -1;
    return ans;
    }
};
