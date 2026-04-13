class Solution {
    void help(int i,int n,vector<int>&nums,int target,int&count)
    {
        if(i==n)
        {
            if(target==0)
            {
                count++;
            }
            return;
        }
        help(i+1,n,nums,target-nums[i],count);
        help(i+1,n,nums,target+nums[i],count);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        int count=0;
         help(0,n,nums,target,count);
         return count;
    }
};
