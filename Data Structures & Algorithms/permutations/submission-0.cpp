class Solution {
    void help(int n,vector<int>&nums,vector<int>temp,
    vector<vector<int>>&ans,vector<int>vis)
    {
          
            if(temp.size()==n)
            {
            ans.push_back(temp);
            return;
            }
          for(int idx=0;idx<n;idx++)
          {
            if(!vis[idx]){
                vis[idx]=1;
               temp.push_back(nums[idx]);
               help(n,nums,temp,ans,vis);
                vis[idx]=0;
               temp.pop_back();
              
            }
          }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(n,0);
        help(n,nums,temp,ans,vis);
        return ans;
    }
};
