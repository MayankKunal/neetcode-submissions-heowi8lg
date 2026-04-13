class Solution {
    void help(int n,vector<int>&nums,vector<int>temp,
    vector<vector<int>>&ans,vector<int>&vis)
    {

            if(temp.size()==n)
            {
                ans.push_back(temp);
                return;
            }

            for(int i=0;i<n;i++)
            {
                  if(!vis[i])
                  {
                     temp.push_back(nums[i]);
                     vis[i]=1;
                     help(n,nums,temp,ans,vis);
                     temp.pop_back();
                     vis[i]=0;
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
