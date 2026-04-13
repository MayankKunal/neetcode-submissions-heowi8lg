class Solution {
    void help(int i,int n,vector<int>&nums,int target,vector<int>temp,
    vector<vector<int>>&ans){
    if(i==n)
    {
        if(target==0)
        ans.push_back(temp);
        return;
    }
    if(target<0) return;
    temp.push_back(nums[i]);
      help(i,n,nums,target-nums[i],temp,ans);
      temp.pop_back();
      help(i+1,n,nums,target,temp,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        help(0,n,nums,target,temp,ans);
        return ans;
    }
};
